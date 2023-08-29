//password is 9986

#include<stdio.h>
#include<string.h>

int main()
{
    FILE *file;
    int press,key;
    int pass;

    printf("\n\n\t\t\t\t\t\t ======================\n");
    printf("\t\t\t\t\t\t File Encrypt Decrypt\n");
    printf("\t\t\t\t\t\t ======================\n\n\n\n");
    printf("\t\t\t\t READ THIS INSTRUCTION CAREFULLY.\n\n\n"
           "\t\t\t\t 1. A key will be used for encryption and decryption.\n"
           "\t\t\t\t 2. Please remember the key.\n"
           "\t\t\t\t 3. Without the key you wont be able to decrypt you text.\n"
           "\t\t\t\t 4. If you entered  wrong key for decryption your data may be lost forever.\n"
           "\t\t\t\t 5. Please clear enc.txt file before encryption.\n"
           "\t\t\t\t 6. After decryption please clear your files else your data might be stolen.\n\n");
    while (1)
    {
        printf("\n\n\n"
               "\t\t\t\t\t * Press 1 Give information to encrypt\n"
               "\t\t\t\t\t * Press 2 Decrypt your text \n"
               "\t\t\t\t\t * Press 3 Read Decrypted file \n"
               "\t\t\t\t\t * press 0 to Exit\n"
               "\n\n\n");
        scanf("%d",&press);
        getchar();
        if(press==1)
        {
            char text[500];
            printf("Enter your text (up to 500 characters):\n");
            fgets(text, sizeof(text), stdin);
            printf("Enter key for encryption\n");
            scanf("%d",&key);

            for (int i = 0; text[i] != '\0'; ++i)
            {
                text[i] = text[i] + key;
            }

            file = fopen("Enc.txt", "a");
            if (file == NULL)
            {
                printf("There is something wrong with your directory.\n");
            }
            else
            {
                fprintf(file, "%s", text);
                fclose(file);
                printf("Text has been encrypted\n\n\n\n");
            }
            printf("\t\t\t\t\t\t ========================\n");
            printf("\t\t\t\t\t\t ========================\n\n\n\n");



        }
        if(press == 2)
        {
            printf("Enter password for decryption\n");
            scanf("%d",&pass);
            if(pass==9986)
            {
                printf("Enter the key which is used for encryption\n");
                scanf("%d",&key);

                char ch;
                FILE *fps, *fpt;
                fps = fopen("Dec.txt", "w");
                if(fps == NULL)
                {
                    printf("Somethings Wrong.Please try again later\n");
                }
                fpt = fopen("Enc.txt", "r");
                if(fpt == NULL)
                {
                    printf("Somethings Wrong.Please try again later\n");
                }
                ch = fgetc(fpt);
                while(ch != EOF)
                {
                    ch = ch-key;
                    fputc(ch, fps);
                    ch = fgetc(fpt);
                }
                fclose(fps);
                fclose(fpt);
                printf("\nFile Decrypted Successfully!\n\n\n");

                printf("\t\t\t\t\t\t ========================\n");
                printf("\t\t\t\t\t\t ========================\n\n\n\n");


            }

            else
            {
                printf("Wrong Password\n");
            }
        }
        if(press==3)
        {
            printf("Enter Password \n");
            scanf("%d",&pass);
            if(pass==9986)
            {
                char ch;
                file = fopen("Dec.txt", "r");

                if (file == NULL)
                {
                    printf("Something went wrong. Please try again later.\n");
                }
                else
                {
                    printf("Password matched.Your Data has been decrypted.look below:\n\n");
                    while ((ch = fgetc(file)) != EOF)
                    {
                        printf("%c", ch);
                    }
                    fclose(file);
                }

            }
            else
            {
                printf("Wrong Password\n");
            }

        }
        if(press == 0)
        {
            printf("Thanks for using our program.\nIf you have any problem, contact us.\n");
            printf("Email: sahedislam605@gmail.com");
        }

    }

}
