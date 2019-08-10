const
        fi='thanthien.inp';
        fo='thanthien.out';
var     a,b,i,dem:longint;
        f:text;
procedure       nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,a,b);
        dem:=0;
        close(f);
end;
function        dao(n:longint):longint;
begin   dao:=0;
        while n <>0 do
        begin
                dao:=dao*10+(n mod 10);
                n:=n div 10;
        end;
end;
function        ucln(a,b:longint):longint;
begin
        while a<>b do
        begin
                if a>b then a:=a-b;
                if b>a then b:=b-a;
        end;
        ucln:=a;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        for i:=a to b do
                if ucln(i,dao(i))=1 then inc(dem);
        writeln(f,dem);
        close(f);
end;
begin
        nhap;
        xuly;
end.




