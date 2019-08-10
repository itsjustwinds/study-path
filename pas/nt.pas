var     n,i:longint;
        //a:array[1..10000] of longint;
function nt(n:longint):boolean;
var     i:longint;
begin
        if n<2 then exit(false);
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then exit(false);
        exit(true);
end;
procedure nhap;
begin
        readln(n);
        if nt(n) then writeln('false')
        else
        begin
                if n=4 then writeln('false')
                else writeln('true');
        end;
end;
begin
        assign(input,'nt.inp');
        assign(output,'nt.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.