uses math;
var
        n,c,i,j:longint;
        a:array[1..16] of longint;
        res:longint;
procedure try(i,k,t:longint);
var     j:longint;
begin
        for j:=k to n do
        begin
                if a[j]+t<=c then
                        res:=max(res,a[j]+t);
                try(i+1,j+1,t+a[j]);
        end;
end;
procedure nhap;
begin
        readln(c,n);
        for i:=1 to n do
                read(a[i]);
        try(1,1,0);
        writeln(res);
end;
begin
        {assign(input,'vcowflix.inp');
        assign(output,'vcowflix.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output);}
end.