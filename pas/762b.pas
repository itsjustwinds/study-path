type
        arr=array[1..300000] of longint;
var
        a,b:arr;
        n,i,j,s1,s2,s3,m,x,dema,demb,sum,chaya,chayb:longint;
        res:int64;
        s:string;
procedure sort(var a:arr;l,r:longint);
var     u,v,x,t:longint;
begin
        u:=l;v:=r;x:=a[random(r-l+1)+l];
        repeat
                while a[u]<x do inc(u);
                while a[v]>x do dec(v);
                if u<=v then
                begin
                        t:=a[u];a[u]:=a[v];a[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if u<r then sort(a,u,r);
        if l<v then sort(a,l,v);
end;
procedure nhap;
begin
        dema:=0;
        demb:=0;
        readln(s1,s2,s3);
        readln(m);
        for i:=1 to m do
        begin
                readln(x,s);
                if s=' USB' then
                begin
                        inc(dema);
                        a[dema]:=x;
                end
                else
                begin
                        inc(demb);
                        b[demb]:=x;
                end;
        end;
        sort(a,1,dema);
        sort(b,1,demb);
        a[dema+1]:=maxlongint;
        b[demb+1]:=maxlongint;
        chaya:=1;
        chayb:=1;
        while (chaya<=dema) and (s1>0) do
        begin
                res:=res+a[chaya];
                inc(chaya);
                dec(s1);
                inc(sum);
        end;
        while (chayb<=demb) and (s2>0) do
        begin
                res:=res+b[chayb];
                inc(chayb);
                dec(s2);
                inc(sum);
        end;
        while (s3>0) and ((chaya<=dema) or (chayb<=demb)) do
        begin
                if a[chaya]<b[chayb] then
                begin
                        res:=res+a[chaya];
                        inc(chaya);
                        dec(s3);
                        inc(sum);
                end
                else
                begin
                        res:=res+b[chayb];
                        inc(chayb);
                        dec(s3);
                        inc(sum);
                end;
        end;
        writeln(sum,' ',res);
end;
begin
        {assign(input,'762b.inp');
        assign(output,'762b.out');
        reset(input);
        rewrite(output); }
        nhap;
        {close(input);
        close(output); }
end.