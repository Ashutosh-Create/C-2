/*
 * Program Description: To grade a multiple choice exam and provide feedback
 *      about the most frequently missed questions.
 * Input: correct answers, student IDs and their answers
 * Output: the answer key, each student's ID and their score as a percentage,
 *      and information about how many students missed each question.
 */

#include <stdio.h>

#define MAX_ANSWERS 50

int fgetAnswers(FILE *examdat, int *student_id, char answers[]);

int
main(void)
{
    FILE *examdat;                  /* Input file - "examdat.txt" */
    FILE *report;                   /* Output file - "report.txt" */
    int i;                          /* Loop index */
    int n;                          /* Number of questions */
    char correct_ans[MAX_ANSWERS];  /* Correct answers */
    int student_id;                 /* Student ID */
    char answers[MAX_ANSWERS];      /* Answers of student */
    int score;                      /* Score of student */
    int input_status;               /* Value returned by scanf */
    int missed[MAX_ANSWERS] = {0};  /* How many students missed each question */

    examdat = fopen("examdat.txt", "r");
    report = fopen("report.txt", "w");

    /* Get number of questions and the correct answers */
    fgetAnswers(examdat, &n, correct_ans);

    /* Write the answer key to output file */
    fprintf(report, "            Exam Report\n");
    fprintf(report, "Question    ");
    for (i = 1; i <= n; i++) {
        fprintf(report, "%d ", i);
    }
    fprintf(report, "\nAnswer      ");
    for (i = 0; i < n; i++) {
        fprintf(report, "%c ", correct_ans[i]);
    }
    fprintf(report, "\n\n");

    /* Write each student's ID and their score to output file */
    fprintf(report, " ID   Score(%%)\n");
    input_status = fgetAnswers(examdat, &student_id, answers);
    score = 0;
    while (input_status == 2) {
        for (i = 0; i < n; i++) {
            if (answers[i] == correct_ans[i]) {
                score++;
            } else {
                missed[i]++;
            }
        }
        fprintf(report, "%d   %.2f\n", student_id, score / (double) n * 100);

        input_status = fgetAnswers(examdat, &student_id, answers);
        score = 0;
    }
    fprintf(report, "\n");

    /* Write how many students missed each question to output file */
    fprintf(report, "Question   ");
    for (i = 1; i <= n; i++) {
        fprintf(report, "%d ", i);
    }
    fprintf(report, "\nMissed by  ");
    for (i = 0; i < n; i++) {
        fprintf(report, "%d ", missed[i]);
    }

    fclose(examdat);
    fclose(report);

    return (0);
}

/*
 * Reads a line containing student ID and answers from input file
 * Returns the value returned by scanf
 */
int
fgetAnswers(FILE *examdat, int *student_id, char answers[])
{
    return fscanf(examdat, "%d %s", student_id, answers);
}
