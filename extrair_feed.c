#include <stdio.h>
#include <string.h>
#include <locale.h>

const char *title = "title>";
const char *link = "link>";
const char *description = "description>";
const char *pubDate = "pubDate>";


void getTag(FILE *f1, char tag[20]){
    int i=0;
    char ch;

    while(((ch = fgetc(f1)) != EOF) && (i<19)){
        tag[i] = ch;
        i++;
        if(ch == '>')
            break;
    }
    tag[i]='\0';
}


void getContent(FILE *f1,char*text){
    int ch;
    int i=0;
    fseek(f1,9,SEEK_CUR);
    while(((ch = fgetc(f1)) != EOF) && (ch != ']')){
        text[i]=ch;
        i++;
    }
    text[i]='\0';
}
void getContentText(FILE *f1,char*text){
    int ch;
    int i=0;
    while(((ch = fgetc(f1)) != EOF) && (ch != '<')){
        text[i]=ch;
        i++;
    }
    text[i]='\0';
}

typedef struct canal{
    char title[700];
    char description[700];
    char link[200];
}canal;

typedef struct noticia{
    char title[700];
    char description[700];
    char link[200];
    char data[75];
}noticia;

int main(){
    setlocale(LC_ALL, "Portuguese");
    FILE *f1, *f2;
    int foundTag,bool=0;
    char ch, tag[20],arqE[100],arqS[100];
    canal c;
    noticia n;
    printf("Insira o nome do arquivo de entrada: ");
    scanf("%s", arqE);
    printf("Insira o nome do arquivo de saída: ");
    scanf("%s", arqS);

    f1 = fopen(arqE, "r");
    f2 = fopen(arqS, "w");
    if (f1 == NULL || f2 == NULL)
    {
        fprintf(stderr, "Erro!! Nao foi possivel abrir os arquivos\n");
    }
    while((ch = fgetc(f1)) !=EOF){
        if(ch == '<'){
            getTag(f1, tag);
            foundTag = 1;
        }
        if((strcmp(tag, title) == 0) && (foundTag == 1)){
            if(bool==0){
                getContentText(f1,c.title);
            }else{
                getContentText(f1,n.title);
            }
            foundTag = 0;
        }
        if((strcmp(tag, description) == 0) && (foundTag == 1)){
            ch = fgetc(f1);
            fseek(f1, -1, SEEK_CUR);
            if(ch=='<'){
                getContent(f1,n.description);
                fprintf(f2,"\t<hr>\n\n");
                fprintf(f2,"\t<h2>%s</h2>\n",n.title);
                fprintf(f2,"\t<p> %s </p>\n\n",n.description);
                fprintf(f2,"\t<a href=""%s""> %s </a>\n",n.link,n.link);
                fprintf(f2,"\t<p> %s </p>\n\n",n.data);
            }else{
                getContentText(f1,c.description);
                fprintf(f2,"<html>\n");
                fprintf(f2,"<head>\n");
                fprintf(f2,"\t<title>%s</title>\n",c.title);
                fprintf(f2,"</head>\n");
                fprintf(f2,"<body>\n\n");
                fprintf(f2,"\t<h1>%s</h1>\n",c.title);
                fprintf(f2,"\t<br>\n");
                fprintf(f2,"\t<a href=""%s""> %s </a>\n",c.link,c.link);
                fprintf(f2,"\t<br>\n");
                fprintf(f2,"\t<p> %s </p>\n\n",c.description);

            }
            foundTag = 0;
            bool=1;
        }
        if((strcmp(tag, link) == 0) && (foundTag == 1)){
            if(bool==0){
                getContentText(f1,c.link);
            }else{
                getContentText(f1,n.link);
            }
            foundTag = 0;
        }
        if((strcmp(tag, pubDate) == 0) && (foundTag == 1)){
            getContentText(f1,n.data);
            foundTag = 0; 
        }
    }
    
    fprintf(f2,"\n</body>\n");
    fprintf(f2,"\n</html>\n");

    fclose(f1);
    fclose(f2);
}