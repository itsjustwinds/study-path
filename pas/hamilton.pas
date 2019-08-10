var
        a:array[1..100,1..100] of boolean;
        dd:array[1..10000] of boolean;
        kq:array[1..100] of longint;
        n,x,y,u,v,m,i:longint;
procedure nhap;
begin
        readln(n,m);
        fillchar(dd,sizeof(dd),false);
        for i:=1 to m do
        begin
                readln(x,y);
                a[x,y]:=true;
                a[y,x]:=true;
        end;
end;
procedure result;
begin
        for i:=1 to n do
                write(kq[i],' ');
        writeln(1,' ');
end;
procedure try(i:longint);
var     j:longint;
begin
        for j:=1 to n do
                if dd[j] and a[kq[i-1],j] then
                begin
                        kq[i]:=j;
                        if i<n then
                        begin
                                dd[j]:=false;
                                try(i+1);
                                dd[j]:=true;
                        end
                        else if a[j,kq[1]] then
                                result;
                end;
end;
begin
        assign(input,'hamilton.inp');
        assign(output,'hamilton.out');
        reset(input);
        rewrite(output);
        nhap;
        fillchar(dd,sizeof(dd),true);
        kq[1]:=1;
        dd[1]:=false;
        try(2);
        close(input);
        close(output);
end.