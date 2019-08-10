uses math;
const
        nmax    =       100;
        dx:array[1..4] of longint = (1,0,-1,0);
        dy:array[1..4] of longint = (0,-1,0,1);
        sx:array[1..4] of longint = (1,1,-1,-1);
        sy:array[1..4] of longint = (1,-1,-1,1);
        tx:array[1..8] of longint = (1,2,2,1,-1,-2,-2,-1);
        ty:array[1..8] of longint = (2,1,-1,-2,-2,-1,1,2);
var
        n,m,chay,dem:longint;
        free:array[1..8,1..8] of boolean;
        dd,c:Array[1..8,1..8] of longint;
        res:int64;
        a,b:Array[1..4] of longint;
        row,col:array[1..8] of int64;
procedure check;
var i,j,u,v,h:longint;
sol:int64;
begin
        inc(chay);
        Sol:=0;
        i:=a[1];j:=b[1];
        for h:=1 to 4 do
          begin
            u:=i+dx[h];v:=j+dy[h];
            while (1<=u)and(u<=8)and(1<=v)and(v<=8) do
              begin
                if dd[u][v]<chay then
                  begin
                    dd[u][v]:=chay;
                    Sol:=Sol+c[u][v];
                  end;
                u:=u+dx[h];v:=v+dy[h];
              end;
          end;
        for h:=1 to 4 do
          begin
            u:=i+sx[h];v:=j+sy[h];
            while (1<=u)and(u<=8)and(1<=v)and(v<=8) do
              begin
                if dd[u][v]<chay then
                  begin
                    dd[u][v]:=chay;
                    Sol:=Sol+c[u][v];
                  end;
                u:=u+sx[h];v:=v+sy[h];
              end;
          end;

        i:=a[2];j:=b[2];
        for h:=1 to 4 do
          begin
            u:=i+sx[h];v:=j+sy[h];
            while (1<=u)and(u<=8)and(1<=v)and(v<=8) do
              begin
                if dd[u][v]<chay then
                  begin
                    dd[u][v]:=chay;
                    Sol:=Sol+c[u][v];
                  end;
                u:=u+sx[h];v:=v+sy[h];
              end;
          end;

        i:=a[3];j:=b[3];
        for h:=1 to 8 do
          begin
            u:=i+tx[h];v:=j+ty[h];
            if (1<=u)and(u<=8)and(1<=v)and(v<=8)and(dd[u][v]<chay) then
             begin
               dd[u][v]:=chay;
               Sol:=Sol+c[u][v];
             end;
          end;

        for i:=1 to 8 do begin row[i]:=0;col[i]:=0; end;
        for i:=1 to 8 do for j:=1 to 8 do if dd[i][j]<chay then
          begin
            inc(row[i],c[i][j]);
            inc(col[j],c[i][j]);
          end;
        for i:=1 to 8 do for j:=1 to 8 do if free[i][j] then
          begin
            if dd[i][j]=chay then h:=0 else h:=c[i][j];
            res:=max(res,Sol+row[i]+col[j]-h);
          end;
end;
procedure DFS(u:longint);
var i,j:longint;
begin
        if u>3 then check
        else
          begin
            for i:=1 to 8 do for j:=1 to 8 do if free[i][j] then
              begin
                free[i][j]:=false;
                a[u]:=i;b[u]:=j;
                DFS(u+1);
                free[i][j]:=true;
              end;
          end;
end;
procedure progress;
var i,j,u,v:longint;
begin
        read(n);
        for i:=1 to 8 do for j:=1 to 8 do free[i][j]:=true;
        for i:=1 to n do
          begin
            read(u,v,j);
            c[u][v]:=j;
            free[u][v]:=false;
          end;
        DFS(1);
        writeln(res);
end;
begin
        assign(input,'bonus13.inp');reset(input);
        assign(output,'bonus13.out');rewrite(output);
          progress;
        close(input);
        close(output);
end.
