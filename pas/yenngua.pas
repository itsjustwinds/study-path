const
        fi='yenngua.inp';
        fo='yenngua.out';
var
        min,max:array [1..100000] of longint;
        a:array [1..1000,1..1000] of longint;
        i,j,n,m,h:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,m,n);
        for i:=1 to m do
        begin
                for j:=1 to n do
                        read(f,a[i,j]);
                readln(f);
        end;
        close(f);
end;
procedure sang;
begin
        for j:=1 to n do
        begin
                h:=a[1,j];
                for i:=2 to n do
                        if a[i,j]>h then h:=a[i,j];
                max[j]:=h;
        end;
        for i:=1 to m do
        begin
                h:=a[i,1];
                for j:=2 to m do
                        if a[i,j]<h then h:=a[i,j];
                min[i]:=h;
        end;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to m do
                for j:=1 to n do
                        if min[i]=max[j] then writeln(f,'yen ngua o vi tri dong ',i,' cot ',j);
        close(f);
end;
begin
        nhap;
        sang;
        xuat;
end.
