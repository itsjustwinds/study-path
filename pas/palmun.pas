const
        fi='palnum.inp';
        fo='palnum.out';
var
        n:int64;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,n);
        close(f);
end;
function dx(x:int64):boolean;
var i:longint;
        s:string;
begin   dx:=true;
        str(x,s);
        for i:=1 to length(s) div 2 do
                if s[i]<>s[length(s)-i+1] then exit(false);
end;
function d(x:int64):int64;
begin
        d:=0;
       while x<>0 do
       begin
        d:=d*10+(x mod 10);
        x:=x div 10;
       end;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        while dx(n)=false do
                n:=n+d(n);
        write(f,n);
        close(f);
end;
begin
        nhap;
        xuat;
end.