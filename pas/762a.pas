type
        ngto=record
                x,y:int64;
        end;
var
        n:int64;
        d,k,i,dem:longint;
        nt:array[1..1000000] of ngto;
procedure nhap;
begin
        dem:=0;
        readln(n,k);
        for i:=1 to trunc(sqrt(n)) do
                if n mod i=0 then
                begin
                        inc(d,2);
                        inc(dem);
                        nt[dem].x:=i;
                        nt[dem].y:=n div i;
                end;
        if sqrt(n)=trunc(sqrt(n)) then
        begin
                inc(d);
                inc(dem);
                nt[dem].x:=trunc(sqrt(n));
                nt[dem].y:=trunc(sqrt(n));
        end;
        if k>d then writeln(-1)
        else
        begin
                if k<=dem then
                        writeln(nt[k].x)
                else writeln(nt[d-k+1].y);
        end;
end;
begin
        {assign(input,'762a.inp');
        assign(output,'762a.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output);}
end.