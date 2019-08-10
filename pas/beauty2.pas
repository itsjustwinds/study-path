const
        fi='beauty.inp';
        fo='beauty.out';
var
        i,n,d:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        close(f);
end;
function soxau(n:longint):boolean;
var t,d:longint;
begin
        t:=0;d:=0;
        while n<>0 do
        begin
                inc(d);
                t:=t+n mod 10;
                n:=n div 10;
        end;
        if t mod d=0 then soxau:=true
        else soxau:=false;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        d:=0;
        for i:=1 to maxlongint do
        begin
                if soxau(i) then
                inc(d);
                if d=n then
                begin
                        write(f,i);
                        break;
                end;
        end;
        close(f);
end;
begin
        nhap;
        xuly;
end.

