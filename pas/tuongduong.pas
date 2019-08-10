const
        fi='tuongduong.inp';
        fo='tuongduong.out';
var     a:array [1..10000] of longint;
        m,n,i,j,d:longint;
        kt:boolean;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,m,n);
        close(f);
end;
function nt(n:longint):boolean;
var
        i:longint;
begin
        nt:=false;
        if n<2 then exit
        else
                for i:=2 to trunc(sqrt(n)) do
                        if n mod i=0 then exit;
        nt:=true;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        i:=0;
                for j:=2 to m div 2 do
                        if nt(j) and (m mod j=0) then
                        begin
                                inc(i);
                                a[i]:=j;
                                while m mod j=0 do
                                        m:=m div j;
                        end;
        kt:=true;
        for j:=1 to i do
        begin
                d:=0;
                while n mod a[j]=0 do
                begin
                        n:=n div a[j];
                        inc(d);
                end;
                if d=0 then
                begin
                        kt:=false;
                        break;
                end;
        end;
        if (kt=true) and (n<>1) then kt:=false;
        write(f,kt); { write(f,m);     }
        close(f);
end;
begin
        nhap;
        xuat;
end.
