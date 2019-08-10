uses math;
var
        fmax,fmin:array[1..10000,1..10000] of longint;
        i,j,n,q:longint;
        a:array[1..10000] of longint;
procedure nhap;
var     x,y:longint;
begin
        readln(n,q);
        for i:=1 to n do
                read(a[i]);
        for i:=1 to n do
        begin
                fmax[i,i]:=a[i];
                fmin[i,i]:=a[i];
                for j:=i+1 to n do
                begin
                        fmax[i,j]:=max(fmax[i,j-1],a[j]);
                        fmin[i,j]:=min(fmin[i,j-1],a[j]);
                end;
        end;
        for i:=1 to q do
        begin
                readln(x,y);
                writeln(fmax[x,y]-fmin[x,y]);
        end;
end;
begin
        {assign(input,'nklineup.inp');
        assign(output,'nklineup.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output);}
end.