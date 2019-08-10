var
        f:array[1..10000,1..10000] of boolean;
        a,d:array[1..10000] of longint;
        dd:array[1..10000] of boolean;
        x:array[1..4] of longint;
        i,j,n,m,tmp,y,dem:longint;
        kt:boolean;
procedure try(i:longint);
var     j,k:longint;
        check:boolean;
begin
        if kt then exit;
        for j:=1 to dem do
        if dd[j] then
        begin
                if (i=1)or (f[a[j],a[x[i-1]]])  then
                begin
                        x[i]:=j;
                        dd[j]:=false;
                        if i=4 then
                        begin
                        if f[a[x[4]],a[x[1]]] then
                        begin
                                kt:=true;
                                exit;
                        end;
                        end
                        else try(i+1);
                        if kt then exit;
                        dd[j]:=true;
                end;
        end;
end;
{procedure dfs;
var
        u,v,last,i,j:longint;
        check:boolean;
        dd:array[1..10000] of boolean;
begin
        for i:=1 to dem do
        begin
                fillchar(dd,dem,true);
                last:=1;
                x[last]:=i;
                dd[i]:=false;
                repeat
                        u:=x[last];
                        dec(last);
                        for v:=1 to dem do
                        begin
                        check:=false;
                        if (f[a[u],a[v]]) and (dd[v]) then
                        begin
                                dd[v]:=false;
                                inc(last);
                                x[last]:=u;
                                inc(last);
                                x[last]:=v;
                                if last=4 then
                                begin
                                        if f[a[x[1]],a[x[4]]] then
                                        begin
                                                kt:=true;
                                                exit;
                                        end
                                        else
                                        begin
                                                dec(last);
                                                check:=true;
                                        end;
                                end;
                                break;
                        end;
                                if (v=dem) and (check=false) then dec(last,2);
                        end;
                until last=0;
        end;
end;
}
procedure nhap;
begin
        readln(n,m);
        for i:=1 to m do
        begin
                readln(tmp,y);
                f[tmp,y]:=true;
                f[y,tmp]:=true;
                inc(d[tmp]);
                inc(d[y]);
        end;
        dem:=0;
        for i:=1 to n do
        if d[i]>=2 then
        begin
                inc(dem);
                a[dem]:=i;
        end;
        if dem<4 then writeln(-1)
        else
        begin
                fillchar(dd,dem,true);
                kt:=false;
                try(1);
                if kt=false then writeln(-1)
                else for i:=1 to 4 do
                        write(x[i],' ');
        end;
        {dfs;
        if kt then
                for i:=1 to 4 do
                        write(x[i],' ')
        else writeln(-1); }
end;
begin
        {assign(input,'travel.inp');
        assign(output,'travel.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output);  }
end.
