const
        fi='numshift.inp';
        fo='numshift.out';
var
        s,s1:string;
        n,i,t,kq,m,k:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);

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
function gt(n:longint):longint;
var
        i:longint;
begin
        gt:=1;
        if n=0 then exit;
        for i:=1 to n do
                gt:=gt*2;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        s:='';
        kq:=n;
        while n<>0 do
        begin
                t:=n mod 2;
                str(t,s1);
                s:=s1+s;
                n:=n div 2;
        end;
        m:=length(s);
        for i:=1 to m do
                s:=s+s[i];
        for i:=2 to m do
        begin
                s1:=copy(s,i,m);
                k:=chuyen10(s1);
                if k>kq then kq:=k;
        end;
        write(f,kq);
        close(f);
end;
begin
        nhap;
        xuat;
end.
