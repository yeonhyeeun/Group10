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

int addSong(Song *s); //성공시 1 리턴, main에서 count+=
void listSong(Song *s, int count);
int updateSong(Song *s); //성공시 1 리턴
int deleteSong(Song *s); //삭제시 likes = -1, 1 리턴, main에서 count—;
void savePlaylist(Song *s, int count);
int loadPlaylist(Song *s); //main에서 count =
int selectMenu(); //선택한 메뉴 번호 리턴
int selectDataNum(Song *s, int count);
void searchSongName(Song *s, int count);
void searchArtist(Song *s, int count);
void searchAlbum(Song *s, int count);
void listBySongName(Song *s, int count);
void listByLikes(Song *s, int count);

void readSong(Song s){ //song 하나 출력
    printf("%s \t%s \t%s \t%d\n", s.name, s.artist, s.album, s.likes);
}

// 1.
int addSong(Song *s){   //성공시 1 리턴, main에서 count+=
    getchar();
    printf("노래 제목을 입력하세요   ");
    fgets(s->name, sizeof(s->name),stdin);
    s->name[strlen(s->name)-1] = '\0';

    printf("아티스트를 입력하세요   ");
    fgets(s->artist, sizeof(s->artist),stdin);
    s->artist[strlen(s->artist)-1] = '\0';

    printf("앨범명을 입력하세요   ");
    fgets(s->album, sizeof(s->album),stdin);
    s->album[strlen(s->album)-1] = '\0';

    printf("좋아요 수를 입력하세요   ");
    scanf("%d", &s->likes);
    
    return 1;
}

//2.
void listSong(Song *s, int count){
    int no=0;
    printf("   NAME\t\tARTIST\t\tALBUM\t\t\tLIKES\n");
    printf("-----------------------------------------------------------------\n");
    for(int i=0; i<count; i++){
        if(s[i].likes==-1) continue;
        printf("%d) ", ++no);
        readSong(s[i]);
    }
}

// 3.
int updateSong(Song *s){    //성공시 1 리턴
    getchar();
    printf("노래 제목을 입력하세요   ");
    fgets(s->name, sizeof(s->name),stdin);
    s->name[strlen(s->name)-1] = '\0';

    printf("아티스트를 입력하세요   ");
    fgets(s->artist, sizeof(s->artist),stdin);
    s->artist[strlen(s->artist)-1] = '\0';

    printf("앨범명을 입력하세요   ");
    fgets(s->album, sizeof(s->album),stdin);
    s->album[strlen(s->album)-1] = '\0';

    printf("좋아요 수를 입력하세요   ");
    scanf("%d", &s->likes);
    
    return 1;
}

// 4.
int deleteSong(Song *s){ //삭제시 likes = -1, 1 리턴, main에서 count-=
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
        fprintf(fp, " %s\n%s\n%s\n%d\n", s[i].name, s[i].artist, s[i].album, s[i].likes);
    }
    fclose(fp);
}

//6.
int loadPlaylist(Song *s){ //main에서 count =
    int i;
    FILE *fp=fopen("playlist.txt", "rt");

    for(i=0; i<SIZE; i++){
        fgets(s[i].name, sizeof(s[i].name),fp);
        s[i].name[strlen(s[i].name)-1] = '\0';
        if(feof(fp)) break;
        fgets(s[i].artist, sizeof(s[i].artist),fp);
        s[i].artist[strlen(s[i].artist)-1] = '\0';
        fgets(s[i].album, sizeof(s[i].album),fp);
        s[i].album[strlen(s[i].album)-1] = '\0';
        fscanf(fp,"%d",&s[i].likes);
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

//8번 
int selectDataNum(Song *s, int count) {
    int no; 
    listSong(s, count);
    printf("\n번호는? (취소:0) ");
    scanf("%d", &no);
    return no; 
} 



//9번 
void searchSongName(Song *s, int count) {
    int scnt = 0; 
    char search[50];

    printf("검색할 노래의 이름은? : ");
    scanf("%s", search);

    printf("\n\n~~~~~~ Play List ~~~~~~\n");
    
    for(int i=0; i < count; i++) {
        if(s[i].likes == -1) continue;
        if(strstr(s[i].name, search)){
            printf("%2d", i+1); 
            readSong(s[i]);  //read역할을 하는 함수 
            scnt++; 
        }
    }
if (scnt == 0) printf("=> 검색된 데이터 없음!");
printf("\n"); 
}


//10번 
void searchArtist(Song *s, int count) {
    int scnt = 0; 
    char search[50];

    printf("검색할 아티스트의 이름은? : ");
    scanf("%s", search);

    printf("\n\n~~~~~~ Play List ~~~~~~\n");
    
    for(int i=0; i < count; i++) {
        if(s[i].likes == -1) continue;
        if(strstr(s[i].artist, search)){
            printf("%2d", i+1); 
            readSong(s[i]);  //read역할을 하는 함수 
            scnt++; 
        }
    }
if (scnt == 0) printf("=> 검색된 데이터 없음!");

printf("\n"); 
}


//11번 
void searchAlbum(Song *s, int count) {
    int scnt = 0; 
    char search[50];

    printf("검색할 앨범의 이름은? : ");
    scanf("%s", search);

    printf("\n\n~~~~~~ Play List ~~~~~~\n");
    
    for(int i=0; i < count; i++) {
        if(s[i].likes == -1) continue;
        if(strstr(s[i].album, search)){
            printf("%2d", i+1); 
            readSong(s[i]);  //read역할을 하는 함수 
            scnt++; 
        }
    }
if (scnt == 0) printf("=> 검색된 데이터 없음!");
printf("\n"); 
}

/*
//12번 
void listBySongName(Song *s, int count){ //곡제목순 정렬 
int i;
for(i=0; i < SIZE; i++) {

    char name[SIZE][SIZE];
    name[i][SIZE] = s->name; 

    qsort(s->name, SIZE, sizeof(s->name[0]), listBySongName);

    for(i=0; i < SIZE; i++) {
        printf("%no.2d %s\n", i+1, name[i]); 
    }
    printf("\n");
}
} 



//13번 
void listByLikes(Song *s, int count){ //좋아요순 정렬 
int i;
for(i=0; i < count; i++) {
    int likes[SIZE];
    likes[i] = s->likes; 

qsort(s->likes, count, sizeof(s->likes),listByLikes);
for(i=0; i < count; i++){
        printf("[%2d] : %40d", i+1, likes[i], s->name); 
    printf("\n"); 
}
    printf("\n"); 
}
}
*/

int main(void){
    Song slist[100];
    int count=0, index=0;
    int menu;
    count = loadPlaylist(slist);
    index = count;

    if(count==0) printf("~~저장된 플레이리스트 없음~~\n");
    else listSong(slist, count);

    while(1){
    menu = selectMenu();

    if(menu==0) break;

    else if(menu==1){
        listSong(slist, count);
    }

    else if(menu==2){
        addSong(&slist[count]);
        count+=1;
        printf("~~ 추가됨 ~~\n");
    }

    else if(menu==3){
        int no = selectDataNum(slist,count);
        if(no==0){
            printf("취소됨!\n");
            continue;
        }
        updateSong(&slist[no-1]);
        printf("~~ 수정됨 ~~\n");
    }

    else if(menu==4){
        int no = selectDataNum(slist,count);
        if(no==0){
            printf("취소됨!\n");
            continue;
        }
        deleteSong(&slist[no-1]);
        count--;
        printf("~~ 삭제됨 ~~\n");
    }

    else if(menu==5){
        savePlaylist(slist, count);
        printf("~~ 저장됨 ~~\n");
    }
/*
    else if(menu==6) { //제목 검색 
        searchSongName(slist, index);
    }

    else if(menu==7) { //가수 검색 
        searchArtist(slist, index);
    }

    else if(menu==8) { //앨범 검색 
        searchAlbum(slist, index);
    }
        
    else if(menu==9) { //곡제목순 정렬  
        listBySongName(slist, index); 
    }

    else if(menu==10) { //좋아요순 정렬  
        listByLikes(slist, index); 
    }
    */
    }
    return 0;
}
