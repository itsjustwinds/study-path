const
        fi='robotnv.inp';
        fo='robotnv.out';
var
        a,l:array [1..1001,1..1001] of longint;
        i,j,n,m:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,m,n);
        for i:=1 to m do
                for j:=1 to n do
                        read(f,a[i,j]);
        close(f);
end;
function max(a,b:longint):longint;
begin
        if a>b then max:=a
        else max:=b;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        l[1,1]:=a[1,1];
        for i:=2 to m do
                l[i,1]:=l[i-1,1]+a[i,1];
        for j:=2 to n do
                l[1,j]:=l[1,j-1]+a[1,j];
        for i:=2 to m do
                for j:=2 to n do
                        l[i,j]:=max(l[i-1,j],l[i,j-1])+a[i,j];
        write(f,l[m,n]);
        close(f);
end;
begin
        nhap;
        xuat;
end.
