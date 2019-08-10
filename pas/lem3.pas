var
        f:array[0..100,0..100] of longint;
        x:array[0..100] of longint;
        dd:array[1..100] of boolean;
        i,n,j:longint;
        res:int64;
procedure try(i,t:longint);
var     j:longint;
begin
        for j:=1 to n do
        if dd[j] then
        begin
                if t+f[x[i-1],j] <res then
                begin
                        dd[j]:=false;
                        x[i]:=j;
                        if (i=n) then res:=t+f[x[i-1],j]
                        else try(i+1,t+f[x[i-1],j]);
                        dd[j]:=true;
                end;
        end;
end;
procedure nhap;
begin
        readln(n);
        for i:=1 to n do
                for j:=1 to n do
                read(f[i,j]);
        res:=maxlongint;
        fillchar(dd,n,true);
                try(1,0);
        writeln(res);
end;
begin
        {assign(input,'lem3.inp');
        assign(output,'lem3.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output);}
end.