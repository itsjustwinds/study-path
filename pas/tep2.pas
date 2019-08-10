const
        fi='supprime.inp';
        fo='supprime.out';
var
        n,i:longint;
        f:text;
procedure       nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        close(f);
end;
function        nt(n:longint):boolean;
var     i:longint;
begin
        nt:=false;
        if n<2 then exit;
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then exit;
        nt:=true;
end;
procedure       xuly;
var dem,dem2:longint;
begin
        assign(f,fo);
        rewrite(f);
        dem:=0;
        dem2:=0;
        for i:=2 to maxlongint do
                if nt(i) then
                begin
                        inc(dem);
                        if nt(dem) then
                        begin
                                inc(dem2);
                                if dem2=n then
                                begin
                                        write(f,i);
                                        break;
                                end;
                        end;
                end;
        close(f);
end;
begin
        nhap;
        xuly;
end.

