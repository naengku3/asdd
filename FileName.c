#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char signInOrSignUp[50];
	char id[50];
	char pw[50];
	char* memberId[30];
	char* memberPw[30];
	for (int i = 0; i < 30; i++) {
		memberId[i] = "0";
		memberPw[i] = "0";
	}
	char memberPwRe[50];
	int idCount = 0;
	int pwCount = 0;
	char console[50];
	int wrongCount = 0;
	// malloc 을 통한 입력받을 명령어 배열 선언
	printf("***온라인 주문관리 시스템입니다.***\n로그인 또는 회원가입을 해주십시오.\n\n");
	printf("(로그인 or 회원가입 입력)");
	while (1) {
		printf("console :");
		scanf("%s", signInOrSignUp);

		if (strcmp(signInOrSignUp, "로그인") == 0) {
			int key = 0;

			printf("아이디 :");
			scanf("%s", id);

			printf("비밀번호 :");
			scanf("%s", pw);

			for (int i = 0; i < 30; i++) {
				if (((!strcmp(memberId[i], id)) && (!strcmp(memberPw[i], pw))) == 1) {
					key = 1;
					 // 어느지점으로 가는지 확인 해야함
				}
				else {
					if (key == 1) break;

					else {
						key = 0;
					}
				}
			}
			
			if (key == 1) {
				puts("로그인 완료!\n");
			}
			else if (key == 0) {
				puts("로그인 실패!\n");
			}
		}

		if (strcmp(signInOrSignUp, "회원가입") == 0) {       //현재 회원가입 띄어쓰기 안됨, scanf로 받고 있기 때문에
			printf("아이디 :");
			for (int i = 0; i < 30; i++) {
				if (memberId[i] == "0") {
					scanf("%s", memberId[i]);
					idCount = i;
					break;
				}
			}
			printf("비밀번호 :");
			for (int p = 0; p < 30; p++) {
				if (memberPw[p] == "0") {
					scanf("%s", memberPw[p]);
					pwCount = p;
					break;
				}
			}
			printf("비밀번호 확인 :");
			scanf("%s", memberPwRe);

			if (strcmp(memberPw[pwCount], memberPwRe) == 0) {
				puts("회원가입 완료!\n");
				 // 어느지점으로 가는지 확인 해야함
			}
			else {
				puts("정보가 일치하지 않습니다.\n");
				memberId[idCount] = ("0");
				memberPw[pwCount] = ("0"); //회원가입에서 부터 시작하지 않고 다시 로그인과 회원가입 고르기로 돌아감
			}
		}
	}
}


	/*
	printf("***온라인 주문관리 시스템입니다.***\n('/명령어' 를 통해 사용할 수 있는 명령어를 확인 할 수 있습니다.)\n\n");
	while (1) {
		printf("console :");
		scanf("%s", console);
		if (strcmp(console, "/명령어") == 0) {
			puts("\n/상품관리 : 상품관리 메뉴에 대한 정보를 확인합니다.");
			puts("/고객관리 : 고객관리 메뉴에 대한 정보를 확인합니다.");
			puts("/주문관리 : 주문관리 메뉴에 대한 정보를 확인합니다.");
			puts("\n상품관리 : 상품관리 메뉴로 이동합니다.");
			puts("고객관리 : 고객관리 메뉴로 이동합니다.");
			puts("주문관리 : 주문관리 메뉴로 이동합니다.\n");
		}	
		
		else if (strcmp(console, "/상품관리") == 0) {
			puts("-상품관리 메뉴로 이동한 뒤, 상품 추가, 수정, 삭제, 목록 출력의 작업을 할 수 있습니다.\n");
		}
		else if (strcmp(console, "/고객관리") == 0) {
			puts("-고객관리 메뉴로 이동한 뒤, 고객 추가, 수정, 삭제, 목록 출력의 작업을 할 수 있습니다.\n");
		}
		else if (strcmp(console, "/주문관리") == 0) {
			puts("-주문관리 메뉴로 이동한 뒤, 고객 추가, 수정, 삭제, 목록 출력, 상세 내역 출력의 작업을 할 수 있습니다.\n");
		}

		else if (strcmp(console, "상품관리") == 0) {
			//상품파트 함수
		}
		else if (strcmp(console, "고객관리") == 0) {
			//고객파트 함수
		}
		else if (strcmp(console, "주문관리") == 0) {
			//주문파트 함수
		}
		else {
			puts("잘못된 명령어입니다.\n");
			wrongCount++;
		
		}
		if (wrongCount == 5) {
			puts("('/명령어' 를 통해 사용할 수 있는 명령어를 확인 할 수 있습니다.)\n");
			wrongCount = 0;
		}
	}
	
	// /명령어 입력 {
		// /상품 상품관리에 대한 메뉴 보기, 일반 상품관리를 입력하면 상품관리에 대한 종합 메뉴로 넘어가서 추가를 할건지 수정을 할건지 삭제를 할건지 물어보기.
		// /상품추가, /상품수정, /상품삭제에 관한 내용설명 + 일반 상품추가, 상품수정, 상품삭제를 입력하면 그 기능에 맞는 함수로 넘어가기.
	
}*/