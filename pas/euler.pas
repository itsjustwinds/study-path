uses math;
var
        f:array[1..1000,1..1000] of longint;
        stack,trace:array[1..1000000] of longint;
        i,j,m,n,u,v,left:longint;
procedure nhap;
var     u,v,c:longint;
begin
        readln(n);
        while not eof do
        begin
                readln(u,v,c);
                f[u,v]:=c;
                f[v,u]:=c;
        end;
end;
procedure push(u:longint);
begin
        inc(left);
        stack[left]:=u;
end;
function get:longint;
begin
        get:=stack[left];
end;
procedure xuly;
begin
        push(1);
        repeat
                u:=get;
                for v:=1 to n do
                if f[u,v]>0 then
                begin
                        dec(f[u,v]);
                        dec(f[v,u]);
                        push(v);
                        break;
                end;
                if u=get then
                begin
                        write(u,' ');
                        dec(left);
                end;
        until left=0;
end;
begin
        assign(input,'euler.inp');
        assign(output,'euler.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.