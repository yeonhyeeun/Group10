<img src = "https://user-images.githubusercontent.com/74174059/118371018-66193b80-b5e5-11eb-8f84-f3d1c57e5e28.jpg" width= "80%">

### 🎶나만의 플레이리스트를 만들어보세요!🎶 

## mini project 주제 및 설명
> 1) 주제 : 나만의 플레이리스틑 직접 만들어보기 
> 2) 설명 : 노래의 제목, 아티스트 이름, 앨범 이름, 이 노래의 좋아요 수를 직접 입력하면서 나만의 플레이리스트를 직접 만들어볼 수 있는 프로그램이다. 


## 1. 기능
* 노래와 노래에 대한 정보 추가 (노래 제목, 아티스트명, 앨범명, 좋아요수 직접 입력 가능)
* 노래 제목 검색
* 아티스트 제목 검색
* 앨범 제목 검색 
* 노래제목 순으로 리스트 정렬
* 좋아요 순으로 리스트 정렬

## 2. 협업 
* 개발일지 - 각 함수 담당자 및 개발 일정 
> 1차 개발(due 05. 02) 
>> 자기소개, 프로그램 주제 선정, 만들어야하는 함수 상의, 각자 역할 나누기 

> 2차 개발(due 05. 09)
>>  각자 맡은 함수 중 과제에서 구현시켜야하는 함수 수정 및 구현. 또한 각자 맡은 파트 업데이트 (수정된 내용 : 구조체 모든 변수 사이즈 40 고정)
>>  히즈넷 공지 내용대로 만들어야하는 함수만 구현 (하연 : 1,3,4,7번 혜은 : 8번 함수)  

> 중간 피드백 (05.10 09:00 pm) 
>> 피드백 내용 : 따로 수정해야할 부분 없음 

> 3차 개발 (due 05.16 12:00 pm) 
>> 과제 공지에 올라온 내용 모두 구현 
>> 프로그램 전체적으로 마무리하기 
>> 2021.05.16 06:14 am. update by hyeeun : readSong함수 추가, 모든 함수 합쳤을때 문법 에러는 나지 않지만 컴파일 과정에서 signal: segmentation fault (core dumped)라는 에러 발생 

> 마지막 피드백 (05.16 12:00 pm)
>> 수정 및 보완해야할 부분 : readSong함수 수정으로 segmentation fault error 해결! 혜은 - 12,13번 함수 컴파일 에러 고쳐오기 

* 프로젝트 참여자
21900207 김하연  21900442 연혜은


-------------------------------------
wiki - function 페이지 
## 9) void searchSongName(Song *s, int count)

플레이 리스트에 있는 노래를 노래 제목으로 찾고싶을때 사용<br/> 
코드<br/>
<img width="454" alt="9번 코드" src="https://user-images.githubusercontent.com/74174059/118611067-6852e400-b7f7-11eb-9d3a-288aae1c96d0.png">

결과화면<br/>
<img width="354" alt="9 SearchName결과화면" src="https://user-images.githubusercontent.com/74174059/118611253-96d0bf00-b7f7-11eb-9692-3fddc118a08f.png">


## 10) void searchArtist(Song *s, int count) 

플레이 리스트에 있는 노래를 노래를 부른 아티스트의 이름으로 찾고싶을때 사용 <br/>
코드<br/>
<img width="450" alt="10번 코드" src="https://user-images.githubusercontent.com/74174059/118611440-d0092f00-b7f7-11eb-8cb3-dd39f571f6fe.png">

결과화면<br/>
<img width="342" alt="10 SearchArtist결과화면" src="https://user-images.githubusercontent.com/74174059/118611484-d9929700-b7f7-11eb-9339-10ce72fd2b40.png">


## 11) void searchAlbum(Song *s, int count)

플레이 리스트에 있는 노래를 노래가 담긴 앨범의 이름으로 찾고싶을때 사용  <br/>  
코드  <br/>  
<img width="439" alt="11번 코드" src="https://user-images.githubusercontent.com/74174059/118611561-f202b180-b7f7-11eb-8778-6c65696b3bd1.png">

결과화면  <br/>
<img width="398" alt="11 searchAlbum결과화면" src="https://user-images.githubusercontent.com/74174059/118611581-f9c25600-b7f7-11eb-8167-cb4cbe3fd55f.png">


## 12) void listBySongName(Song *s, int count)

플레이 리스트의 목록을 노래 제목순으로 정렬<br/>
코드<br/>
<img width="480" alt="12번 코드" src="https://user-images.githubusercontent.com/74174059/118611669-1199da00-b7f8-11eb-959f-ff4d0af09427.png">

결과화면<br/>
<img width="404" alt="12 ListbyName결과화면" src="https://user-images.githubusercontent.com/74174059/118611694-178fbb00-b7f8-11eb-9474-70df18aedf15.png">


## 13) void listByLikes(Song *s, int count)

플레이 리스트의 목록을 노래가 가지는 좋아요 개수순으로 정렬<br/>
코드<br/>
<img width="393" alt="13번 코드" src="https://user-images.githubusercontent.com/74174059/118611822-32622f80-b7f8-11eb-9e16-2f7f6f196e7c.png">

결과화면<br/>
<img width="320" alt="13 ListbyLikes결과화면" src="https://user-images.githubusercontent.com/74174059/118611866-38f0a700-b7f8-11eb-9448-ca1ecc513c53.png">


## 추가적으로 필요했던 함수들 
> 1) 정렬에 필요한 compare함수<br/> 
>> <img width="381" alt="정렬에 필요한 비교함수" src="https://user-images.githubusercontent.com/74174059/118611935-473ec300-b7f8-11eb-872f-931c64fb0a37.png">
<br/>

> 2) 오름차순 정렬함수 <br/> 
>> <img width="367" alt="오름차순 정렬함수" src="https://user-images.githubusercontent.com/74174059/118611984-51f95800-b7f8-11eb-89f9-41c8b6f0d6eb.png">


