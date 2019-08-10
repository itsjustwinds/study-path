const
        fi='palnum.inp';
        fo='palnum.out';
var
        n:int64;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);read(f,n);
        close(f);
end;
function dx(n:int64):boolean;
var
        i:longint;
        s:string;
begin
        str(n,s);
        dx:=true;
        for i:=1 to (length(s) div 2) do
                if s[i]<>s[length(s)-i+1] then
                begin
                        dx:=false;
                        exit;
                end;
end;
function dao(n:int64):int64;
begin   dao:=0;
        while n<>0 do
        begin
                dao:=dao*10+(n mod 10);
                n:=n div 10;
        end;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        while not(dx(n)) do
        n:=n+dao(n);
        write(f,n);
        close(f);
end;
begin
        nhap;
        xuat;
end.
