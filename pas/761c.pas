uses math;
type
        aa=set of char;
var
        f:array[1..50,1..50] of char;
        lock:array[1..50,1..3] of longint;
        n,m,i,j,e,t,res:longint;
        k:array[1..3] of aa;
        dd:array[1..3] of boolean;
        minn:array[1..3] of longint;
procedure nhap;
begin
        k[1]:=k[1]+['#'];
        k[1]:=k[1]+['*'];
        k[1]:=k[1]+['&'];
        k[2]:=['0'..'9'];
        k[3]:=['a'..'z'];
        fillchar(dd,sizeof(dd),false);
        readln(n,m);
        for i:=1 to n do
        begin
                for j:=1 to m do
                begin
                        read(f[i,j]);
                end;
                readln;
        end;
        for i:=1 to n do
                for t:=1 to 3 do
                if f[i,1] in k[t] then dd[t]:=true;
        for t:=1 to 3 do
        if dd[t]=false then
        begin
                for i:=1 to n do
                        for j:=1 to m do
                        if f[i,j] in k[t] then
                        begin
                                lock[i,t]:=j;
                                break;
                        end;
        end;
        for t:=1 to 3 do
        if dd[t]=false then
        begin
                minn[t]:=1000;
                for i:=1 to n do
                if lock[i,t]<>0 then
                        minn[t]:=min(minn[t],lock[i,t]);
        end;
        repeat
                e:=1000;
                for t:=1 to 3 do
                if (dd[t]=false) then
                        e:=min(e,minn[t]);
                if e=1000 then break;
                res:=res+min(e-1,m-e+1);
                dd[e]:=true;
        until false;
        writeln(res);
end;
begin
        assign(input,'761c.inp');
        assign(output,'761c.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.