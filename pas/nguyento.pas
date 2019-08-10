const
        fi='nguyento.inp';
        fo='nguyento.out';
var
        a:array [1..10000000] of longint;
        dd:array [1..10000000] of boolean;
        s:ansistring;
        i,d,x,j:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,s);
        close(f);
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
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        fillchar(dd,sizeof(dd),false);
        d:=0;
        for i:=1 to length(s) do
        begin
               x:=0;
               j:=i;
               while j<=length(s) do
               begin
                if not (s[j] in ['1'..'9']) then break;
                x:=x*10+ord(s[j])-48;
                if x>5000000 then break;
                if (ngto(x)) and (dd[x]=false) then
                begin
                        inc(d);
                        a[d]:=x;
                        dd[x]:=true;
                end;
                inc(j);
               end;
        end;
        writeln(f,d);
        for i:=1 to d do
                write(f,a[i],' ');
        close(f);
end;
begin
        nhap;
        xuat;
end.


