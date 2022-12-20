/* 
int maximizingXor(int l, int r) {
int m=0;
for(int i=l;i<=r-1;i++){
    for(int j=l+1;j<=r;j++){
        m=max(m,i^j);
    }
}
return m;
}

*/