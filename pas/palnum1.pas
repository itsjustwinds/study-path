const
        fi='palnum.inp';
        fo='palnum.out';
var
        n:int64;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        close(f);
end;
function dao(n:int64):int64;
begin
        dao:=0;
        while n<>0 do
        begin
                dao:=dao*10+n mod 10;
                n:=n div 10;
        end;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        if n=dao(n) then
                write(f,n)
        else
        begin
                while n<>dao(n) do
                        n:=n+dao(n);
                write(f,n);
        end;
        close(f);
end;
begin
        nhap;
        xuly;
end.

