uses math;
var
        root:array[1..200000] of longint;
        rootd:array[1..200000] of longint;
        dist:array[1..200000] of longint;
        seed,i,j,n,k:longint;
        res:int64;
procedure nhap;
var     u,v:longint;
begin
        readln(n,k);
        for i:=1 to n do
        begin
                readln(u,v);
                rootd[i]:=u;
                root[i]:=v;
                if v=0 then seed:=i;
        end;
end;
function finddist(n:longint):longint;
begin
        if n=seed then exit(0);
        if dist[n]<>0 then exit(dist[n]);
        dist[n]:=1+finddist(root[n]);
        exit(dist[n]);
end;
procedure xuly;
begin
        for i:=1 to k do
        begin
                res:=0;
                for j:=1 to n do
                if rootd[j]=i then
                        res:=max(res,finddist(j));
                writeln(res);
        end;
end;
begin
        assign(input,'fselect.inp');
        assign(output,'fselect.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.