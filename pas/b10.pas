const
        fi='b10.inp';
        fo='b10.out';
var
        n:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,n);
        close(f);
end;
function nt(x:longint):boolean;
var i:longint;
begin   nt:=false;
        if x<2 then exit;
        for i:=2 to trunc(sqrt(x)) do
                if x mod i=0 then exit;
        nt:=true;
end;
function minn(x:longint):longint;
var a:longint;
begin   a:=x+1;
        while nt(a)=false do
                inc(a);
        minn:=a;
end;
function maxn(x:longint):longint;
var a:longint;
begin   a:=x-1;
        while nt(a)=false do
                dec(a);
        maxn:=a;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        if nt(n) then
                if n>((minn(n)+maxn(n)) div 2) then write(f,'true') else write(f,'false')
        else write(f,'false');

        close(f);
end;
begin
        nhap;
        xuat;
end.