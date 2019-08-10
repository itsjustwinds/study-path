const
        fi='primediv.inp';
        fo='primediv.out';
var
        n:int64;
        i:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        close(f);
end;
function nt(n:int64):boolean;
var
        i:longint;
begin
        nt:=false;
        if n<2 then exit;
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then exit;
        nt:=true;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        if nt(n) then write(f,n)
        else
                for i:=2 to trunc(sqrt(n))  do
                        if (nt(i)) and (n mod i=0) then
                        begin
                                write(f,i,' ');
                                while n mod i=0 do
                                        n:=n div i;
                                if nt(n) then
                                begin
                                        write(f,n);
                                        break;
                                end;
                                if n=1 then break;
                        end;
        close(f);
end;
begin
        nhap;
        xuly;
end.