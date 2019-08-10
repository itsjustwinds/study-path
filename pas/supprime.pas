const
        fi='supprime.inp';
        fo='supprime.out';
var
        n,i,k,t:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        close(f);
end;
function nt(n:longint):boolean;
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
        k:=0;t:=0;
        for i:=2 to maxlongint do
                if nt(i) then
                begin
                        inc(k);
                        if nt(k) then inc(t);
                        if t=n then
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