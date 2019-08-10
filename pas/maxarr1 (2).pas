uses math;
var
        f,maxn:array[0..100000] of int64;
        i,n,t:longint;
function tinh(n:longint):int64;
begin
        if f[n]<>0 then exit(f[n]);
        if n mod 2=0 then
        begin
                f[n]:=tinh(n div 2);
                exit(f[n]);
        end
        else
        begin
                f[n]:=tinh(n div 2)+tinh(n div 2+1);
                exit(f[n]);
        end;
end;
function tinhmaxn(n:longint):int64;
begin
        if maxn[n]<>0 then exit(maxn[n]);
        maxn[n]:=max(tinhmaxn(n-1),tinh(n));
        exit(maxn[n]);
end;
procedure nhap;
begin
        readln(t);
        f[0]:=0;
        f[1]:=1;
        maxn[0]:=0;
        maxn[1]:=1;
        while t>0 do
        begin
        dec(t);
        readln(n);
        if n=0 then writeln(0)
        else
        begin
        if maxn[n]=0 then
                maxn[n]:=max(tinhmaxn(n-1),tinh(n));
        writeln(maxn[n]);
        end;
        end;
end;
begin
        {assign(input,'maxarr1.inp');
        assign(output,'maxarr1.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output);}
end.
