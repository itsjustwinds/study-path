const
        fi='sothanthien.inp';
        fo='sothanthien.out';
var
        a,b,kq,i:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,a,b);
        close(f);
end;
function dao(a:longint):longint;
begin
        dao:=0;
        while a<>0 do
        begin
                dao:=dao*10+a mod 10;
                a:=a div 10;
        end;
end;
function ucln(a,b:longint):longint;
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
        kq:=0;
        for i:=a to b do
        if ucln(i,dao(i))=1 then
                inc(kq);
        write(f,kq);
        close(f);
end;
begin
        nhap;
        xuly;
end.