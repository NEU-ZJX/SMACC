struct SsrFPatternRotate2 : smacc::SmaccState<SsrFPatternRotate2, SS>
{
  using SmaccState::SmaccState;

  typedef smacc::transition<EvActionSucceded<smacc::SmaccMoveBaseActionClient>, SsrFPatternForward2> reactions;

  static void onDefinition()
  {
    float angle = 0;
    if (SS::direction() == TDirection::LEFT)
      angle = -90;
    else
      angle = 90;

    static_configure<NavigationOrthogonal, SbRotate>(angle);
    static_configure<ToolOrthogonal, SbToolStop>();
  }

  void onInitialize()
  {
    auto &superstate = this->context<SS>();
    ROS_INFO("[SsrFpattern] Fpattern rotate: SS current iteration: %d/%d", superstate.iteration_count, SS::total_iterations());
  }
};