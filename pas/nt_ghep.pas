const
        fi='NT_GHEP.inp';
        fo='NT_GHEP.OUT';
var
        k,x,d,m:longint;
        i,j,a,b:int64;
        f:text;
        s,s1:string;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,k);
        close(f);
end;
function cs(n:int64):longint;
begin
        cs:=0;
        while n<>0 do
        begin
                inc(cs);
                n:=n div 10;
        end;
end;
function nt(n:int64):boolean;
var
        i:longint;
begin
        nt:=false;
        if n<2 then exit;
        if n>=2 then
                for i:=2 to trunc(sqrt(n)) do
                        if n mod i=0 then exit;
        nt:=true;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        d:=0;i:=1;
        while d<k do
        begin
                while nt(i)=false do inc(i);
                a:=i;
                i:=i+1;
                while nt(i)=false do inc(i);
                b:=i;
                for m:=1 to cs(b) do
                        a:=a*10;
                a:=a+b;
                if nt(a) then inc(d);
                if d=k then
                begin
                        write(f,a);
                end;
                i:=i+1; { write(f,a);break;}
        end;
        close(f);
end;
begin
        nhap;
        xuat;
end.
