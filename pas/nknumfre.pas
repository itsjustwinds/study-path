var
        a,b:longint;
        i,j:longint;
        res:longint;
function dao(n:longint):longint;
begin
        dao:=0;
        while n<>0 do
        begin
                dao:=dao*10+n mod 10;
                n:=n div 10;
        end;
end;
function ucln(a,b:longint):longint;
begin
        if a mod b=0 then exit(b)
        else exit(ucln(b,a mod b));
end;
procedure nhap;
begin
        readln(a,b);
        for i:=a to b do
                if ucln(i,dao(i))=1 then inc(res);
        writeln(res);
end;
begin
        {assign(input,'nknumfre.inp');
        assign(output,'nknumfre.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output);}c
end.