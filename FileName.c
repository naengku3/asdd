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
	// malloc �� ���� �Է¹��� ��ɾ� �迭 ����
	printf("***�¶��� �ֹ����� �ý����Դϴ�.***\n�α��� �Ǵ� ȸ�������� ���ֽʽÿ�.\n\n");
	printf("(�α��� or ȸ������ �Է�)");
	while (1) {
		printf("console :");
		scanf("%s", signInOrSignUp);

		if (strcmp(signInOrSignUp, "�α���") == 0) {
			int key = 0;

			printf("���̵� :");
			scanf("%s", id);

			printf("��й�ȣ :");
			scanf("%s", pw);

			for (int i = 0; i < 30; i++) {
				if (((!strcmp(memberId[i], id)) && (!strcmp(memberPw[i], pw))) == 1) {
					key = 1;
					 // ����������� ������ Ȯ�� �ؾ���
				}
				else {
					if (key == 1) break;

					else {
						key = 0;
					}
				}
			}
			
			if (key == 1) {
				puts("�α��� �Ϸ�!\n");
			}
			else if (key == 0) {
				puts("�α��� ����!\n");
			}
		}

		if (strcmp(signInOrSignUp, "ȸ������") == 0) {       //���� ȸ������ ���� �ȵ�, scanf�� �ް� �ֱ� ������
			printf("���̵� :");
			for (int i = 0; i < 30; i++) {
				if (memberId[i] == "0") {
					scanf("%s", memberId[i]);
					idCount = i;
					break;
				}
			}
			printf("��й�ȣ :");
			for (int p = 0; p < 30; p++) {
				if (memberPw[p] == "0") {
					scanf("%s", memberPw[p]);
					pwCount = p;
					break;
				}
			}
			printf("��й�ȣ Ȯ�� :");
			scanf("%s", memberPwRe);

			if (strcmp(memberPw[pwCount], memberPwRe) == 0) {
				puts("ȸ������ �Ϸ�!\n");
				 // ����������� ������ Ȯ�� �ؾ���
			}
			else {
				puts("������ ��ġ���� �ʽ��ϴ�.\n");
				memberId[idCount] = ("0");
				memberPw[pwCount] = ("0"); //ȸ�����Կ��� ���� �������� �ʰ� �ٽ� �α��ΰ� ȸ������ ����� ���ư�
			}
		}
	}
}


	/*
	printf("***�¶��� �ֹ����� �ý����Դϴ�.***\n('/��ɾ�' �� ���� ����� �� �ִ� ��ɾ Ȯ�� �� �� �ֽ��ϴ�.)\n\n");
	while (1) {
		printf("console :");
		scanf("%s", console);
		if (strcmp(console, "/��ɾ�") == 0) {
			puts("\n/��ǰ���� : ��ǰ���� �޴��� ���� ������ Ȯ���մϴ�.");
			puts("/������ : ������ �޴��� ���� ������ Ȯ���մϴ�.");
			puts("/�ֹ����� : �ֹ����� �޴��� ���� ������ Ȯ���մϴ�.");
			puts("\n��ǰ���� : ��ǰ���� �޴��� �̵��մϴ�.");
			puts("������ : ������ �޴��� �̵��մϴ�.");
			puts("�ֹ����� : �ֹ����� �޴��� �̵��մϴ�.\n");
		}	
		
		else if (strcmp(console, "/��ǰ����") == 0) {
			puts("-��ǰ���� �޴��� �̵��� ��, ��ǰ �߰�, ����, ����, ��� ����� �۾��� �� �� �ֽ��ϴ�.\n");
		}
		else if (strcmp(console, "/������") == 0) {
			puts("-������ �޴��� �̵��� ��, �� �߰�, ����, ����, ��� ����� �۾��� �� �� �ֽ��ϴ�.\n");
		}
		else if (strcmp(console, "/�ֹ�����") == 0) {
			puts("-�ֹ����� �޴��� �̵��� ��, �� �߰�, ����, ����, ��� ���, �� ���� ����� �۾��� �� �� �ֽ��ϴ�.\n");
		}

		else if (strcmp(console, "��ǰ����") == 0) {
			//��ǰ��Ʈ �Լ�
		}
		else if (strcmp(console, "������") == 0) {
			//����Ʈ �Լ�
		}
		else if (strcmp(console, "�ֹ�����") == 0) {
			//�ֹ���Ʈ �Լ�
		}
		else {
			puts("�߸��� ��ɾ��Դϴ�.\n");
			wrongCount++;
		
		}
		if (wrongCount == 5) {
			puts("('/��ɾ�' �� ���� ����� �� �ִ� ��ɾ Ȯ�� �� �� �ֽ��ϴ�.)\n");
			wrongCount = 0;
		}
	}
	
	// /��ɾ� �Է� {
		// /��ǰ ��ǰ������ ���� �޴� ����, �Ϲ� ��ǰ������ �Է��ϸ� ��ǰ������ ���� ���� �޴��� �Ѿ�� �߰��� �Ұ��� ������ �Ұ��� ������ �Ұ��� �����.
		// /��ǰ�߰�, /��ǰ����, /��ǰ������ ���� ���뼳�� + �Ϲ� ��ǰ�߰�, ��ǰ����, ��ǰ������ �Է��ϸ� �� ��ɿ� �´� �Լ��� �Ѿ��.
	
}*/