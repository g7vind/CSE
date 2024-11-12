#include <stdio.h>
#define st 10 // MAX STATES
#define ch 10 // MAX INPUTS

// DS
int tra[st][st][ch], inv[st][ch][st], nfa[st][ch][st];
int ecl[st][st];

char  inp[st];
int vis[st], see[st], inpcnt = 0;

int mapInp(char in) {
	for(int i = 0; i <= inpcnt; i++) if(inp[i] == in) return i;
	inp[inpcnt++] = in; return inpcnt - 1;
}

void eps(int org, int s) {
	if(vis[s]) return;
	vis[s] = 1;
	ecl[org][s] = 1;
	for(int i = 0; i < st; i++) if(tra[s][i][0]) eps(org, i);
}

void main() {
	inp[inpcnt++] = 'e';
	
	FILE *fp = fopen("td.txt", "r");
	int s1, s2; char in;
	while(fscanf(fp, "%d %c %d", &s1, &in, &s2) != EOF) {
		see[s1] = 1;
		see[s2] = 1;
		int index = mapInp(in);
		tra[s1][s2][index] = 1;
		inv[s1][index][s2] = 1;
	}
	fclose(fp);
	
	for(int i = 0; i < st; i++) {
		for(int j = 0; j < st; j++) vis[j] = 0;
		eps(i, i);
	}
	
	for(int i = 0; i < st; i++) {
		if(!see[i]) continue;
		for(int j = 1; j < inpcnt; j++) {
			printf("\n-> START   %d x %c\n", i, inp[j]);
			for(int k = 0; k < st; k++) {
				if(!see[k]) continue;
				if(ecl[i][k]) {
					printf("-> CONFIRM %d-e-%d\n", i, k);
					for(int l = 0; l < st; l++) {
						if(inv[k][j][l]) {
							printf("\t-> CONFIRM %d-%c-%d\n", k, inp[j], l);
							for(int m = 0; m < st; m++) {
								if(ecl[l][m]) {
									printf("\t\t-> CONFIRM %d-e-%d\n", l, m);
									nfa[i][j][m] = 1;
								}
							}
						}
					}
				}
			}
		}
	}
	
	printf("\nNFA Transitions\n");
	for(int i = 0; i < st; i++) {
		for(int j = 1; j < inpcnt; j++) {
			for(int k = 0; k < st; k++) {
				if(nfa[i][j][k] && see[i] && see[k]) {
					printf("%d - %c - %d\n", i, inp[j], k);
				}
			}
		}
	}			 
}