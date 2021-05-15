#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 40

typedef struct {
    char name[SIZE];
    char artist[SIZE];
    char album[SIZE];
    int likes;
} Song;

// 1.
int addSong(Song *s){   //성공시 1 리턴, main에서 count+=
    printf("노래 제목을 입력하세요   ");
    while(getchar()!='\n');
    fgets(s->name, sizeof(s->name),stdin);
    s->name[strlen(s->name)-1] = '\0';

    printf("아티스트를 입력하세요   ");
    while(getchar()!='\n');
    fgets(s->artist, sizeof(s->artist),stdin);
    s->artist[strlen(s->artist)-1] = '\0';

    printf("앨범명을 입력하세요   ");
    while(getchar()!='\n');
    fgets(s->album, sizeof(s->album),stdin);
    s->album[strlen(s->album)-1] = '\0';

    printf("좋아요 수를 입력하세요   ");
    scanf("%d", &s->likes);

    return 1;
}

//2.
void listSong(Song *s, int count){
    int no=0;
    printf("NAME      ARTIST    ALBUM     LIKES     \n");
    printf("----------------------------------------\n");
    for(int i=0; i<count; i++){
        if(s[i].likes==-1) continue;
        printf("%d ", ++no);
        readSong(s[i]);
    }
}

// 3.
int updateSong(Song *s){    //성공시 1 리턴
    printf("노래 제목을 입력하세요   ");
    while(getchar()!='\n');
    fgets(s->name, sizeof(s->name),stdin);
    s->name[strlen(s->name)-1] = '\0';

    printf("아티스트를 입력하세요   ");
    while(getchar()!='\n');
    fgets(s->artist, sizeof(s->artist),stdin);
    s->artist[strlen(s->artist)-1] = '\0';

    printf("앨범명을 입력하세요   ");
    while(getchar()!='\n');
    fgets(s->album, sizeof(s->album),stdin);
    s->album[strlen(s->album)-1] = '\0';

    printf("좋아요 수를 입력하세요   ");
    scanf("%d", &s->likes);

    return 1;
}

// 4.
int deleteSong(Song *s){ //삭제시 likes = -1, 1 리턴, main에서 count—;
    int del;

    printf("정말로 삭제하시겠습니까?(삭제: 1)   ");
    scanf("%d", &del);
    if(del==1) s->likes = -1;
    printf("삭제되었습니다\n");
    return 1;
}

//5.
void savePlaylist(Song *s, int count){
    FILE *fp=fopen("playlist.txt", "wt");
    for(int i=0; i<count; i++){
        if(s[i].likes==-1) continue;
        fprintf(fp, "%s", s[i].name);
        fprintf(fp, "%s", s[i].artist);
        fprintf(fp, "%s", s[i].album);
        fprintf(fp, "%d", s[i].likes);
    }
    fclose(fp);
    printf("~~저장됨~~\n");
}

//6.
int loadPlaylist(Song *s){ //main에서 count =
    int i;
    FILE *fp=fopen("playlist.txt", "rt");
    for(i=0; i<100; i++){
        fgets(s[i].name, sizeof(s->name), fp);
        if(feof(fp)) break;
        fscanf(fp, "%s", s[i].name);
        fscanf(fp, "%s", s[i].artist);
        fscanf(fp, "%s", s[i].album);
        fscanf(fp, "%d", s[i].likes);
    }
    fclose(fp);
    return i;
}

//7.
int selectMenu(){ //선택한 메뉴 번호 리턴
    int menu;

    printf("\n\n~~~~~~ Play List ~~~~~~\n");
    printf("1. 플레이리스트 조회\n");
    printf("2. 곡 추가\n");
    printf("3. 곡 정보 수정\n");
    printf("4. 곡 삭제 \n");
    printf("5. 파일 저장\n");
    printf("6. 제목 검색\n");
    printf("7. 가수 검색\n");
    printf("8. 앨범 검색\n");
    printf("9. 곡제목순 정렬\n");
    printf("10. 좋아요순 정렬\n");
    printf("0. 종료\n");

    printf("    => ");
    scanf("%d", &menu);

    return menu;
}


// 8.
int selectDataNum(Song *s, int count) {
    int no; 
    //listSong(s, count);
    printf("번호는? (취소:0) ");
    scanf("%d", &no);
    return no; 
}

int main(void){
    Song slist[SIZE];
    int count=0, index=0;
    int menu;
    count = loadfile(slist);
    index = count;
    if(count==0) printf("~~저장된 플레이리스트 없음~~\n");
    else listSong(slist, count);
    while(1){
    menu = selectMenu();

    if(menu==0) break;

    else if(menu==2){
        addSong(&slist[count++]);
        printf("~~ 추가됨 ~~\n");
    }
    else if(menu==3){
        int no = selectDataNum(slist,count);
        if(no==0){
            printf("취소됨!\n");
            continue;
        }
        else{
            updateSong(&slist[no-1]);
            printf("~~ 수정됨 ~~\n");
            continue;
        }
    }
    else if(menu==4){
        listSong(slist, count);
        int no = selectDataNum(slist,index);
        if(no==0){
            printf("취소됨!\n");
            continue;
        }
        else{
            deleteSong(&slist[no-1);
            printf("~~ 삭제됨 ~~\n");
            continue;
        }
    }
    return 0;
}
