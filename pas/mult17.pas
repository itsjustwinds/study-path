const
        fi='mult17.inp';
        fo='mult17.out';
var
        s,s1,kq:string;
        m:longint;
        n:int64;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,s);
        close(f);
end;
function mu(u,v:longint):int64;
var
        i:longint;
begin
        mu:=1;
        for i:=1 to u do
                mu:=mu*v;
end;
function chuyen10(s:string):int64;
var
        i,j:longint;
begin
        chuyen10:=0;
        j:=length(s);
        for i:=1 to length(s) do
                chuyen10:=chuyen10+mu(j-i,2)*(ord(s[i])-48);
end;
function chuyen2(n:longint):string;
var      x:string;
begin
        chuyen2:='';
        while n<>0 do
        begin
                str(n mod 2,x);
                chuyen2:=x+chuyen2;
                n:=n div 2;
        end;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        n:=chuyen10(s)*17;
        kq:=chuyen2(n);
        write(f,kq);
        close(f);
end;
begin
        nhap;
        xuat;
end.