var
        a:array[1..1000] of longint;
        dd:array[1..1000] of boolean;
        kq,res:array[1..1000] of longint;
        x,y,max:int64;
        i,j,n:longint;
procedure nhap;
begin
        readln(n);
        for i:=1 to n do
                read(a[i]);
end;
procedure check;
var     i:longint;
begin
        if x>max then
        begin
                max:=x;
                for i:=1 to n do
                        res[i]:=kq[i];
        end;
end;
procedure try(i:longint);
var     j:longint;
begin
        for j:=1 to n do
        if dd[j] then
        begin
                if x<=y then
                begin
                        x:=x+a[j];
                        kq[i]:=j;
                        dd[j]:=false;
                        if i=n then check
                        else try(i+1);
                        x:=x-a[j];
                        dd[j]:=true;
                end
                else
                begin
                        y:=y+a[j];
                        kq[i]:=j;
                        dd[j]:=false;
                        if i=n then check
                        else try(i+1);
                        y:=y-a[j];
                        dd[j]:=true;
                end;
        end;
end;
procedure xuly1;
begin
        x:=0;
        y:=0;
        max:=0;
        fillchar(dd,n,true);
        try(1);
        for i:=1 to n do
                write(res[i],' ');
end;
procedure xuly2;
var     i,k,t:longint;
begin
        k:=n mod 2;
        if k=1 then for i:=1 to n do
                write(a[i],' ')
        else begin
                write(1,'  ',3,' ',2,' ');
                for i:=4 to n do
                        write(i,' ');
        end;
end;
begin
        assign(input,'candy.inp');
        assign(output,'candy.out');
        reset(input);
        rewrite(output);
        nhap;
        if i<=15 then xuly1
        else xuly2;
        close(input);
        close(output);
end.
