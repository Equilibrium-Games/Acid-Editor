﻿using System;
using System.Collections.Generic;
using System.Linq;

namespace Acid.UI.Docking
{
    public class DockPanelState : IEquatable<DockPanelState>
    {
        #region Property Region

        public List<DockRegionState> Regions { get; set; }

        #endregion

        #region Constructor Region

        public DockPanelState()
        {
            Regions = new List<DockRegionState>();
        }

        #endregion

        #region Comparison Region

        public bool Equals(DockPanelState other) => Regions.SequenceEqual(other.Regions);
        public static bool operator ==(DockPanelState first, DockPanelState second) => first.Equals(second);
        public static bool operator !=(DockPanelState first, DockPanelState second) => !first.Equals(second);
        public override int GetHashCode() => base.GetHashCode();
        public override bool Equals(object obj) => Equals(obj as DockPanelState);

        #endregion
    }
}
