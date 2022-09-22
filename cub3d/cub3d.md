cub3D
miniLibX를 사용한 나의 첫 RayCaster

요약: 이 프로젝트는 최초의 FPS이자 세계적으로 유명한 90년대 게임으로부터 영감을 얻었습니다. 이 프로젝트를 수행함으로써 여러분은 ray-casting의 세계를 탐험할 것입니다. 여러분의 목표는 미로 안에서 스스로의 길을 찾아 역동적인 뷰를 만드는 것입니다.

Contents
Chapter	Contents	page
1	Foreword	2
2	Goals	3
3	Common Instrunctions	4
4	Mandatory part - Get_next_line	5
5	Bonus part	9
6	Examples	11
Chapter 1
Foreword
울펜슈타인 3D(Wolfenstein 3D) 는 세계적으로 유명한 개발자인 존 카멕과 존 로메로가 이드 소프트웨어에서 개발하고, 1992년 아포기 소프트웨어에서 출시한 진정한 역사상 최초의 "1인칭 슈팅 게임" 이다.

Doom... DoOm... DOom... DooM... (picture)
그림 1.1 : 존 로메로 (왼쪽) 과 존 카멕 (오른쪽) 이 후세를 위한 포즈를 취하고 있음

울펜슈타인 3D는 둠 (이드 소프트웨어, 1993), 둠 II(이드 소프트웨어, 1994), 듀크 뉴켐 3D (3D 렐름, 1996), 퀘이크 (이드 소프트웨어, 1996) 과 같은 게임들의 시초격이 되는 작품이며, 또한 비디오 게임계의 영원한 이정표가 되었다.

이제, 여러분이 역사를 다시 세울 차례입니다...


Chapter 2
Goals
이번 프로젝트의 목표는 이전에 진행했던 이러한 프로젝트와 비슷합니다 : 엄격함 (Rigor), C언어 사용하기, 기본적인 알고리즘 사용하기, 정보 검색 등

그래픽 디자인 프로젝트로서, cub3D는 창, 색상, 이벤트, 모양 채우기 등과 같은 분야에서 여러분의 능력 향상을 도울 것입니다.

결론적으로, cub3D는 재미있고 실용적인 수학적 응용 프로그램을 구체적인 내용 이해 없이도 탐구할 수 있게 돕는 뛰어난 놀이터가 됩니다.

인터넷에서 찾을 수 있는 수많은 문서들에게 도움을 받으면, 여러분은 수학을 도구삼아 우아하고 효율적인 알고리즘을 제작할 수 있습니다.

Wolfenstein 3D. (picture)
이 프로젝트를 시작하기 전에 오리지널 게임을 테스트해보는 걸 추천합니다.

http://users.atw.hu/wolf3d/


Chapter 3
Common Instructions
프로젝트는 Norm 규칙에 맞춰 작성되어야 합니다. 보너스 파일/함수가 존재할 경우, 그 또한 norm 검사에 포함되며 norm error가 있을 시 0점을 받게 됩니다.

정의되지 않는 동작인 경우 이외에는 여러분이 작성하신 프로그램이 예기치 않게 종료되면 안됩니다 (segmentation fault, bus error, double free 등). 만약 여러분의 프로그램이 예기치 않게 종료된다면, 작동하지 않은 것으로 간주되어 평가에서 0점을 받게 됩니다.

필요한 경우 heap에 할당된 모든 메모리 공간은 적절하게 해제되어야 합니다. 메모리 누수는 용납되지 않습니다.

과제에서 필요한 경우, -Wall -Wextra -Werror 플래그를 지정하여 컴파일을 수행하는 Makefile을 제출해야 합니다. Makefile은 relink 되어서는 안 됩니다.

Makefile은 최소한 $(NAME), all, clean, fclean, re 규칙을 포함해야 합니다.

프로젝트에 보너스를 제출하려면, Makefile에 보너스 규칙을 포함해야 합니다. 이 보너스 규칙은 프로젝트의 메인 파트에서 금지되었던 모든 다양한 헤더, 라이브러리, 또는 함수들을 추가하여야 합니다. 보너스 과제는 반드시 _bonus.{c/h}라는 별도의 파일에 있어야 합니다. 반드시 수행하여야 하는 메인 파트의 평가와 보너스 파트의 평가는 별도로 이뤄집니다.

만일 프로젝트에서 여러분의 libft 사용을 허용한다면, 소스들과 관련 Makefile을 함께 루트 폴더 안에 있는 libft 폴더에 복사해야 합니다. 프로젝트의 Makefile은 우선 libft의 Makefile을 사용하여 라이브러리를 컴파일한 다음, 프로젝트를 컴파일해야 합니다.

이 과제물을 제출할 필요가 없고, 채점 받을 필요가 없을지라도, 저희는 여러분들이 프로젝트를 위한 테스트 프로그램을 만들 것을 권장합니다. 이것은 여러분의 과제물과 동료들의 과제물을 쉽게 테스트할 수 있게 도울 것입니다. 또한, 평가를 진행할 때 이러한 테스트 프로그램들이 특히 유용하다는 사실을 알게 될 것입니다. 평가 시에는 여러분의 테스트 프로그램과 평가 받는 동료의 테스트 프로그램들을 당연히 자유롭게 사용할 수 있습니다.

할당된 git 저장소에 과제물을 제출하세요. 오직 git 저장소에 있는 과제물만 등급이 매겨질 것입니다. Deepthought가 평가하는 과제의 경우엔, 동료평가 이후에 Deepthought가 수행됩니다. 만약 Deepthought 평가 중에 오류가 발생한다면, 그 즉시 평가는 중지될 것입니다.


Chapter 4
Mandatory part - cub3D

프로그램 이름	cub3D
제출할 파일	제작에 필요한 모든 파일들
Makefile 규칙	all, clean, fclean, re, bonus
인자	*.cub 형식의 맵
사용가능한
외부 함수	open, close, read, write, printf, malloc, free, perror, strerror, exit
math 라이브러리 내의 모든 함수들 (-lm man man 3 math)
MinilibX 라이브러리 내의 모든 함수들
직접 만든 libft	사용 가능
설명	여러분은 미로 내부의 1인칭 뷰를 "현실적인" 3D 그래픽으로 표현하셔야 합니다. 이러한 표현은 앞서 말한 Ray-Casting 원리를 통해 생성되어야 합니다.
제약은 다음과 같습니다:

반드시 miniLibX를 사용해야 합니다. (운영체제에서 이용 가능한 라이브러리와 과제에서 제공되는 소스 중 하나를 사용하셔야 합니다) 만약 제공받은 소스를 이용해 작업하기로 했다면, Libft의 공통 지침 (Common Instructions) 과 같은 규칙을 따라야 합니다.

작업 창 관리는 부드럽게 동작하여야 합니다. (창 최소화, 다른 창으로 전환 등의 동작)

벽이 어느 쪽 (동, 서, 남, 북) 을 향하고 있는지에 따라 서로 다른 벽 텍스쳐 (텍스쳐는 직접 골라 사용하세요) 를 사용하여야 합니다.

여러분의 프로그램은 벽 대신 아이템 (스프라이트) 을 표시할 수 있어야 합니다.

여러분의 프로그램은 바닥과 천장의 색을 서로 다르게 설정할 수 있어야 합니다.

언젠가 Deepthought가 여러분의 프로젝트를 평가하게 될 날을 대비하여, 여러분의 프로그램은 두 번째 인자가 "--save" 일 때 첫 번째로 렌더링된 이미지를 bmp 형식으로 저장해야 합니다.

두 번째 인자가 없을 경우, 프로그램은 다음 규칙을 준수하면서 화면 창에 영상을 표시합니다.

키보드의 왼쪽과 오른쪽 화살표 키는 카메라의 시점을 회전시킬 수 있어야 합니다. (왼쪽 및 오른쪽 보기)

W, A, S, D 키는 맵 내부에서 카메라를 이동시킬 수 있어야 합니다. (캐릭터의 이동)

ESC를 누르면 창이 닫히고 프로그램이 정상적으로 종료되어야 합니다.

창 상단 표시줄에 있는 빨간색 십자가를 클릭하면 창이 닫히고 프로그램이 정상적으로 종료되어야 합니다.

지도에 표시된 화면 크기가 디스플레이 해상도보다 크면, 현재 디스플레이의 해상도에 따라 윈도우 크기가 설정될 것입니다.

minilibX의 이미지를 사용하는 것을 적극 권장합니다.

여러분의 프로그램은 먼저 .cub 확장자를 가진 지도 파일을 첫 번째 인자로 받아와야 합니다.

지도는 4개의 문자로만 구성되어야 합니다. (빈 공간인 경우 0, 벽인 경우 1, 아이템은 2, 플레이어의 시작 위치와 그에 따른 시점은 N, S, E, W)

간단하고 유효한 맵의 예시입니다 :

111111
100101
102001
1100N1
111111
지도는 벽으로 둘러쌓여 있어야 합니다. 그렇지 않다면 프로그램은 오류를 반환해야 합니다.

지도 내용을 제외하고는, 각각의 요소들은 하나 혹은 그 이상의 빈 줄로 분리될 수 있습니다.

지도 내용이 항상 맨 마지막에 있어야 한다는 점을 제외하면, 다른 요소들은 어떤 순서로든 파일 내부에 저장되어 있을 수 있습니다.

지도를 제외하고, 요소에서 각 유형의 정보는 하나 이상의 공백으로 구분될 수 있습니다.

지도는 파일 내에서 보이는 것처럼 불러 올 수 있어야 합니다. 공백은 지도의 유효한 부분이며, 처리는 여러분의 몫입니다. 여러분은 규칙대로 만들어진 모든 종류의 지도를 제대로 불러올 수 있어야 합니다.

각 요소 (지도 제외) 의 첫 번째 정보는 (하나 또는 두개의 문자로 구성된) 유형 식별자이며, 각 객체에 대한 모든 구체적인 정보는 다음과 같은 엄격한 규칙을 따릅니다 :

해상도 :

R 1920 1080
유형 식별자 : R
x 렌더 크기
y 렌더 크기
북쪽 벽 텍스쳐 :

NO ./path_to_the_north_texture
유형 식별자 : NO
북쪽 벽 텍스쳐가 담겨있는 경로
남쪽 벽 텍스쳐 :

SO ./path_to_the_south_texture
유형 식별자 : SO
남쪽 벽 텍스쳐가 담겨있는 경로
서쪽 벽 텍스쳐 :

WE ./path_to_the_west_texture
유형 식별자 : WE
서쪽 벽 텍스쳐가 담겨있는 경로
동쪽 벽 텍스쳐 :

EA ./path_to_the_east_texture
유형 식별자 : EA
동쪽 벽 텍스쳐가 담겨있는 경로
아이템 텍스쳐 :

S ./path_to_the_sprite_texture
유형 식별자 : S
아이템 텍스쳐가 담겨있는 경로
바닥 색상 :

F 220,100,0
유형 식별자 : F
[0, 255] 사이의 RGB 색상 : 0, 255, 255
천장 색상 :

C 225,30,0
유형 식별자 : C
[0, 255] 사이의 RGB 색상 : 0, 255, 255
필수 구현 파트에서 사용할 간단한 .cub 파일의 예:

R 1920 1080
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

S ./path_to_the_sprite_texture
F 220,100,0
C 225,30,0

		1111111111111111111111111
		1000000000110000000000001
		1011000001110000002000001
		1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10002000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111

맵 파일에서 잘못된 구성이 발견되었을 경우, 프로그램을 올바르게 종료하고 "Error\n" 을 반환한 후, 여러분이 정한 명시적 오류 메시지가 표시되어야 합니다.
