uses math;

    const       fi = 'KCOLLECT.inp';
                fo = 'KCOLLECT.out';
                max = 1000000;
                d : array[1..2] of longint = (0, 1);
                c : array[1..2] of longint = (1, 0);

    type        banghi = record
                x, y : longint;
                end;
    var
        s : array[1..100, 1..100] of char;
        free :array[1..100, 1..100] of longint ;
        number, low : array[1..100,1..100] of longint;
        tong , u, v, deg,  num , a, q: array[1..max] of longint;
        head, f : array[0..max] of longint;
        adj : array[1..10000000] of longint;
        visited : array[1..max] of boolean;
        stack : array[1..max] of banghi;
        n, count, componentcount, top, m, id : longint;


    procedure     readf;
      var
        i, j  : longint;
      begin


        readln(m ,n);
        for i := 1 to m do
          for j := 1 to n do
             if j <> n then read(s[i,j]) else readln(s[i,j]);

      end;

    procedure     init;
      begin

        fillchar(number, sizeof(number), 0);
        fillchar(free, sizeof(free), 0);

        top := 0;
        count := 0;
        componentcount := 0;
      end;

    procedure     push(x, y : longint);
      begin
        inc(top);
        stack[top].x := x;
        stack[top].y := y;
      end;

    function      pop : banghi ;
      begin
        pop := stack[top];
        dec(top);
      end;

    procedure     visit(x, y:longint); {tim kiem theo chieu sau bat dau tai u}
      var
         i , a1, a2 : longint; res : banghi;
      begin

        inc(count);  number[x, y] := count; { danh stt tham u}
        low[x, y] := count ; {tam thoi coi u co cung toi u }
        push(x, y);

        for i := 1 to 2 do
          begin
           a1 := x + d[i];
           a2 := y + c[i];

           if (a1 <= m ) and (a2 <= n) and (free[a1, a2] = 0) and (s[a1,a2] <> '#')  then
           if number[a1, a2] <> 0 then { neu ma v da tham }
             low[x, y] := min(low[x, y], number[a1, a2]) {giam low[u] nho nhat co the }
           else { neu v chua tham }
             begin
               visit(a1, a2) ; { tham v }
               low[x, y] := min(low[x, y], low[a1, a2]);
             end;

          end;

        if s[x,y] = 'W' then
          begin
             a1 := x;
             a2 := y - 1;
             if (a1 >= 1) and (a2 >= 1) and (free[a1,a2] = 0 ) and (s[a1,a2] <> '#') then
                if number[a1, a2] <> 0 then { neu ma v da tham }
                 low[x, y] := min(low[x, y], number[a1, a2]) {giam low[u] nho nhat co the }
                else { neu v chua tham }
                begin
                  visit(a1,a2) ; { tham v }
                 low[x, y] := min(low[x, y], low[a1, a2]);
                end;
          end;

        if s[x,y] = 'N' then
          begin
             a1 := x - 1;
             a2 := y ;

             if (a1 >= 1) and (a2 >= 1) and (free[a1,a2] = 0 ) and (s[a1,a2] <> '#') then
                if number[a1, a2] <> 0 then { neu ma v da tham }
                 low[x, y] := min(low[x, y], number[a1, a2]) {giam low[u] nho nhat co the }
                else { neu v chua tham }
                begin
                  visit(a1,a2) ; { tham v }
                 low[x, y] := min(low[x, y], low[a1, a2]);
                end;
          end;

        { sau khi chay het vong nay ta thay moi dinh thuoc DFS goc u da tham}


        if low[x, y] = number[x, y] then { neu u la chot }
          begin
             inc(componentcount);
             repeat
               res := pop;
               free[res.x, res.y] := componentcount;
               if s[res.x, res.y] in ['0'..'9'] then
                tong[componentcount] := tong[componentcount] + ord(s[res.x, res.y]) - 48;
             until (res.x = x) and (res.y = y)
          end;
      end ;

    procedure   solve;
      var
        dem, i, j : longint;
      begin

        for i := 1 to m do
          for j := 1 to n do
          if (number[i, j] = 0) and (s[i,j] <> '#') then
            visit(i, j);
      end;

    procedure   creat;
      var
        i, j , k, a1, a2, dem : longint;
      begin

          dem := 0;
          for i := 1 to m do
             for j := 1 to n do
             if s[i,j] <> '#' then
               begin
                  for k := 1 to 2 do
                    begin
                       a1 := i + d[k];
                       a2 := j + c[k];
                       if (a1 <= m ) and (a2 <= n) and (s[a1,a2] <> '#') then
                         if (free[i,j] <> free[a1,a2])  then
                            begin
                              inc(dem);
                              u[dem] := free[i,j];
                              v[dem] := free[a1,a2];

                              inc(deg[free[i,j]]);
                            end;
                    end;
                  if s[i,j] = 'W' then
                    begin
                        a1 := i ;
                        a2 := j - 1;
                        if (a1 >= 1) and (a2 >= 1) and (s[a1,a2] <> '#') then
                           if (free[i,j] <> free[a1,a2]) then
                           begin
                              inc(dem);
                              u[dem] := free[i,j];
                              v[dem] := free[a1,a2];
                              inc(deg[free[i,j]]);

                            end;
                    end;

                  if s[i,j] = 'N' then
                    begin
                        a1 := i -1 ;
                        a2 := j ;
                        if (a1 >= 1) and (a2 >= 1) and (s[a1,a2] <> '#') then
                           if (free[i,j] <> free[a1,a2]) then
                            begin
                              inc(dem);
                              u[dem] := free[i,j];
                              v[dem] := free[a1,a2];
                              inc(deg[free[i,j]]);
                            end;
                    end;
               end;

          head[1] := 1;
          for i := 2 to componentcount do
                head[i] := head[i-1] + deg[i-1];

          for i := 1 to dem do
             begin
                adj[head[u[i]]] := v[i];
                inc(head[u[i]]);
             end;

          for i := 1 to componentcount do
             dec(head[i]);
      end;

    procedure     DFS(u: longint);
      var
         v : longint;
      begin
         visited[u] := true;
         for v := head[u-1] + 1 to head[u] do
         if (not visited[adj[v]]) then
             DFS(adj[v]);
         num[u] := id;
         q[id] := u;
         dec(id);
      end;

    procedure      process;
      var
         u , i, j : longint;
      begin

        fillchar(visited,sizeof(visited),false);
        id := componentcount;
        for u:= 1 to componentcount do
        if not visited[u] then DFS(u);

        m := free[1,1];
        fillchar(f, sizeof(f), 255);
        f[q[componentcount]] := tong[q[componentcount]];
          for i := componentcount - 1 downto 1 do
            begin

               for j := head[q[i]- 1] + 1 to head[q[i]] do
               if f[adj[j]] >-1 then
                  if f[adj[j]] + tong[q[i]] > f[q[i]] then f[q[i]] := f[adj[j]] + tong[q[i]] ;
                if f[q[i]] = -1 then f[q[i]] := tong[q[i]];
               if q[i] = m then exit;

            end;
      end;

    BEGIN
        assign(input,'kcollect.inp');
        assign(output,'kcollect.out');
        reset(input);
        rewrite(output);
        readf;
        init;
        solve;
        creat;
        process;
        write(f[free[1,1]]);
        close(input);
        close(output);
    END.
