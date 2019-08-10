const
        fi='b4.inp';
        fo='b4.out';
var
        n,k,i,max,maxtu:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        close(f);
end;
function tu(n:longint):longint;
var i:longint;
begin   tu:=0;
        for i:=1 to n do
                if n mod i=0 then tu:=tu+i;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        max:=tu(1);
        maxtu:=1;
        for i:=2 to n-1 do
                if tu(i)>max then
                begin
                        max:=tu(i);
                        maxtu:=i;
                end;
        writeln(f,maxtu);
        for i:=1 to maxtu do
                if maxtu mod i=0 then write(f,i,' ');
        close(f);
end;
begin
        nhap;
        xuly;
end.

