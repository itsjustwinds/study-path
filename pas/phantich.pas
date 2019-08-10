const
fi='phantich.inp';
fo='phantich.out';
var     n:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        close(f);
end;
function nt(n:longint):boolean;
var     i:longint;
begin
        nt:=false;
        if n<2 then exit;
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then exit;
        nt:=true;
end;
procedure xuly;
var i:longint;
begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to n do
                if nt(i)=true then write(f,i,' ');
        close(f);
end;
begin
        nhap;
        xuly;
end.
