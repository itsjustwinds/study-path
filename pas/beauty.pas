const
        fi='beauty.inp';
        fo='beauty.out';
var
        n,i,dem:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        close(f);
end;
function bt(n:longint):boolean;
var     t,dem:longint;
begin   t:=0;dem:=0;
        while n<>0 do
        begin   inc(dem);
                t:=t+n mod 10;
                n:=n div 10;
        end;
        if t mod dem=0 then bt:=true
        else bt:=false;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        dem:=0;
        for i:=1 to maxlongint do
        begin
                if bt(i) then inc(dem);
                if dem=n then
                begin
                        n:=i;
                        break;
                end;
        end;
        write(f,n);
        close(f);
end;
begin
        nhap;
        xuat;
end.
