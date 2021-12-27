#include <unistd.h>
#include "students.h"

int file_size(FILE *f, long *size)
{
    if (fseek(f, 0L, SEEK_END))
        return EXIT_FAILURE;
    if (ftell(f) < 0)
        return EXIT_FAILURE;
    *size = ftell(f);
    fseek(f, 0L, SEEK_SET);
    return EXIT_SUCCESS;
}

int read_bin(FILE *f)
{
    long size;
    if (file_size(f, &size))
        return EXIT_FAILURE;
    if (size % sizeof (student_t) != 0)
        return EXIT_FAILURE;
    student_t student = { 0 };
    while (fread(&student, sizeof (student), 1, f))
    {
        printf("%s\n", student.surname);
        printf("%s\n", student.name);
        printf("%" PRIu32, student.grades[0]);
        printf(" %" PRIu32, student.grades[1]);
        printf(" %" PRIu32, student.grades[2]);
        printf(" %" PRIu32, student.grades[3]);
        printf("\n\n");
    }
    return EXIT_SUCCESS;
}

int create_bin(FILE *f)
{
    student_t student = { 0 };
    while (scanf("%s%s" "%" SCNu32 "%" SCNu32 "%" SCNu32 "%" SCNu32, student.surname, student.name, &student.grades[0], &student.grades[1], &student.grades[2], &student.grades[3]) == 6)
    {
        if (strlen(student.surname) > SIZE_SURNAME || strlen(student.surname) > SIZE_NAME)
            return EXIT_FAILURE;
        fwrite(&student, sizeof (student_t), 1, f);
    }
    return EXIT_SUCCESS;
}

double average(FILE *f)
{
    double aver = 0, count = 0, sum = 0;
    student_t student = { 0 };

    if (fseek(f, 0L, SEEK_SET))
        return -1;
    while (fread(&student, sizeof (student_t), 1, f))
    {
        for (size_t i = 0; i < SIZE_GRADE; i++)
        {
            sum += student.grades[i];
        }
        aver += sum / SIZE_GRADE;
        sum = 0;
        count++;
    }
    aver /= count;
    return aver;
}

int get_by_pos(FILE *f, long pos, student_t *a)
{
    if (fseek(f, 0L, SEEK_SET))
        return EXIT_FAILURE;
    for (long i = 0; i <= pos; i++)
        if (fread(a, sizeof (student_t), 1, f) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int put_by_pos(FILE *f, long pos, student_t a)
{
    if (fseek(f, (long)pos * (long)sizeof (student_t), SEEK_SET))
        return EXIT_FAILURE;
    fwrite(&a, sizeof (student_t), 1, f);
    return EXIT_SUCCESS;
}

int del_field(FILE *f, char *filename, long pos, long *count)
{
    student_t student = { 0 };
    while (pos < *count - 1)
    {
        if (get_by_pos(f, pos + 1, &student))
            return EXIT_FAILURE;

        put_by_pos(f, pos, student);
        pos++;
    }

    (*count)--;

    if (*count == 0)
        return EXIT_FAILURE;

    if (truncate(filename, (long)(*count) * sizeof (student_t)))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int delete_on_average(FILE *f, long *count, char *filename)
{
    double general_aver = average(f);
    if (general_aver < 0)
        return EXIT_FAILURE;
    for (long i = 0; i < *count; i++)
    {
        double sum = 0;
        student_t student = { 0 };

        if (get_by_pos(f, i, &student))
            return EXIT_FAILURE;
        for (size_t j = 0; j < SIZE_GRADE; j++)
            sum += student.grades[j];
        double aver = sum / SIZE_GRADE;
        if (aver < general_aver)
        {
            if (del_field(f, filename, i, count))
                return EXIT_FAILURE;
            i--;
        }
    }
    return EXIT_SUCCESS;
}

int start_of_line(char *substr, char *str)
{
    for (size_t i = 0; i < strlen(substr); i++)
        if (substr[i] != str[i])
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void output_substr(FILE *fin, FILE *fout, char *substr, long *count)
{
    student_t student = { 0 };
    fseek(fin, 0L, SEEK_SET);
    while (fread(&student, sizeof (student_t), 1, fin))
        if (!start_of_line(substr, student.surname))
        {
            fwrite(&student, sizeof (student_t), 1, fout);
            (*count)++;
        }
}

int sort(FILE *f)
{
    long size;
    if (file_size(f, &size))
        EXIT_FAILURE;
    long count = size / (sizeof (student_t));

    student_t a = { 0 };
    student_t b = { 0 };

    for (long i = 0; i < count; i++)
        for (long j = 0; j < count; j++)
        {
            if (get_by_pos(f, i, &a) || get_by_pos(f, j, &b))
                return EXIT_FAILURE;
            int coincidence = strcmp(a.surname, b.surname);

            if (coincidence < 0)
            {
                put_by_pos(f, j, a);
                put_by_pos(f, i, b);
            }
            if (coincidence == 0 && strcmp(a.name, b.name) < 0)
            {
                put_by_pos(f, j, a);
                put_by_pos(f, i, b);
            }
        }
    read_bin(f);
    return EXIT_SUCCESS;
}


