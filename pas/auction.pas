const
        fi='auction.inp';
        fo='auction.out';
var
        a,b,i,t:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,a,b);
        close(f);
end;
function dx(n:longint):boolean;
var
        i:longint;
        s:string;
begin
        dx:=true;
        str(n,s);
        for i:=1 to length(s) div 2 do
                if s[i]<>s[length(s)-i+1] then
                begin
                        dx:=false;
                        break;
                end;
end;
function ngto(n:longint):boolean;
var
        i:longint;
begin
        ngto:=false;
        if n<2 then exit;
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then exit;
        ngto:=true;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        t:=0;
        for i:=a to b do
                if dx(i)  then
                        if ngto(i) then
                        inc(t);
        write(f,t);
        close(f);
end;
begin
        nhap;
        xuly;
end.
