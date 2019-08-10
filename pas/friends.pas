const
        fi='friends.inp';
        fo='friends.out';
var
        a:array [1..1000000] of longint;
        n,k,i,j,dem:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(F);
        readln(f,n,k);
        for i:=1 to n do
                readln(f,a[i]);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        dem:=0;
        for i:=1 to n do
                for j:=n downto i do
                        if a[i]+a[j]=k then inc(dem);
        write(f,dem);
        close(f);
end;
begin
        nhap;
        xuat;
end.