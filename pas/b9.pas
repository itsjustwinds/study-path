const
        fo='b9.out';
var
        i:longint;
        f:text;
function nt(x:longint):boolean;
var i:longint;
begin
        nt:=false;
        if x<2 then exit;
        for i:=2 to trunc(sqrt(x)) do
                if x mod i=0 then exit;
        nt:=true;
end;
function mersen(x:longint):boolean;
var dem,a:longint;
begin   mersen:=true;dem:=0;
        a:=x+1;
        while a mod 2=0 do
        begin
                a:=a div 2;
                inc(dem);
        end;
        if nt(dem) and (a =1) then exit;
        mersen:=false;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to 10000 do
                if nt(i) then
                        if mersen(i) then writeln(f,i);
        close(f);
end;
begin
        xuat;
end.