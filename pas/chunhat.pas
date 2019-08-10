const
        fi='chunhat.inp';
        fo='chunhat.out';
var
        a:array [1..250,1..250] of longint;
        i,j,n,m,d:longint;
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
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        d:=0;
        for i:=1 to m do
                for j:=1 to n do
                        if (a[i,j]=1) and (a[i,j+1]=0) and (a[i+1,j]=0) then
                                inc(d);
        write(f,d);
        close(f);
end;
begin
        nhap;
        xuat;
end.

