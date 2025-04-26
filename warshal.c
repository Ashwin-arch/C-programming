#include<stdio.h>
#define MAX 10
void warshall(int n,int r[MAX][MAX]);
int main(){
  int n;
  int r[MAX][MAX];
  int i,j;
  printf("Enter the nuber of nodes:\n");
  scanf("%d",&n);
  printf("Enter the adjacency matrix");
  for(i=0;i<n;i++){
  for(j=0;j<n;j++){
    scanf("%d",&r[i][j]);
  }
}
warshall(n,r);
return 0;
}
void warshall(int n, int r[MAX][MAX]){
    int i,j,k;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                r[i][j]=r[i][j]||r[i][k]&&r[k][j];
            }
        }
    }
    printf("Transitive closure Matrix is:\n");
    for(i=0;i<=n;i++){
        printf("\t %d",i);
    }
    printf("\n\t--------------------------------------------\n");
for(i = 1; i <= n; i++) {
printf("%d|\t", i);
for(j = 1; j <= n; j++) {
printf("%d\t", r[i][j]);
}
printf("\n");
}

}
