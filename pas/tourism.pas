const
        maxn=100000;
var
        a:array[1..100,1..100] of longint;
        dd:array[1..100] of boolean;
        x,kq:array[1..100] of longint;
        i,j,n,m,tmp,y,max:longint;
procedure result(t:longint);
var     i:longint;
begin
        if t+a[x[n],1]<max then
        begin
                max:=t+a[x[n],1];
                for i:=1 to n do
                        kq[i]:=x[i];
        end;
end;
procedure try(i,t:longint);
var     j:longint;
begin
        for j:=2 to n do
                if dd[j] then
                        if t+a[x[i-1],j]<max then
                        begin
                                x[i]:=j;
                                dd[j]:=false;
                                if i=n then
                                        result(t+a[x[i-1],j])
                                else try(i+1,t+a[x[i-1],j]);
                                dd[j]:=true;
                        end;
end;
procedure nhap;
begin
        readln(n,m);
        for i:=1 to n do
                for j:=i to n do
                        if i=j then a[i,j]:=0
                        else
                        begin
                                a[i,j]:=maxn;
                                a[j,i]:=maxn;
                        end;
        for i:=1 to m do
        begin
                readln(tmp,y,a[tmp,y]);
                a[y,tmp]:=a[tmp,y];
        end;
        max:=maxn;
        fillchar(dd,n,true);
        dd[1]:=false;
        x[1]:=1;
        try(2,0);
        for i:=1 to n do
                write(kq[i],' ');
        writeln(1);
        writeln(max);
end;
begin
        assign(input,'tourism.inp');
        assign(output,'tourism.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.